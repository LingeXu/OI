#include <bits/stdc++.h>
#define N 100010
#define LOG 18
typedef long long ll;
using namespace std;
int n, q;
int d[N], c[N], s[N], nx[N], id[N];
int fa[N][LOG];
ll sum[N][LOG];
void preprocess() {
    for(int i = 0; i < LOG; i++) {
        fa[0][i] = 0;
        sum[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        fa[i][0] = nx[i];
        sum[i][0] = 1LL * c[nx[i]];
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            sum[j][i] = sum[j][i - 1] + sum[fa[j][i - 1]][i - 1];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> d[i] >> c[i];
    int top = 0;
    for(int i = 1; i <= n; i++) {
        while(top > 0 && d[i] > s[top]) {
            nx[id[top]] = i;
            top--;
        }
        s[++top] = d[i];
        id[top] = i;
    }
    
    /*for(int i = 1; i <= n; i++)
        cout << nx[i] << '\n';*/

    preprocess();
    for(int i = 1; i <= q; i++) {
        int r, v;
        cin >> r >> v;

        //cout << i << ':';

        int remain = v - c[r];
        if(remain <= 0) {
            cout << r << '\n';
            continue;
        }

        /*while(remain > 0) {
            now = nx[now];
            if(now == 0) break;
            remain -= c[now];
        }*/

        if(remain > 0) {
            for(int j = LOG - 1; j >= 0; j--) {
                if(sum[r][j] >= 1LL * remain)  continue;
                remain -= sum[r][j];
                r = fa[r][j];
                if(r == 0) break;
            }
            cout << nx[r] << '\n';
        }
    }
    return 0;
}