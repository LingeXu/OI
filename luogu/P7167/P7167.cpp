#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, q;
int d[N], c[N], s[N], nx[N], id[N];
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

    for(int i = 1; i <= q; i++) {
        int r, v;
        cin >> r >> v;
        int remain = v - c[r], now = r;
        while(remain > 0) {
            now = nx[now];
            if(now == 0) break;
            remain -= c[now];
        }
        cout << now << '\n';
    }
    return 0;
}