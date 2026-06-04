#include <bits/stdc++.h>
#define N 1010
#define M 1010
typedef long long ll;
using namespace std;
int n, m;
ll ans = 0;
int h[M], L[M], R[M];
int l[M], r[M];
char c[N][M];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int top1 = 0;
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == '.')
                h[j] += 1;
            else    h[j] = 0;
            while(top1 > 0 && h[l[top1]] > h[j]) 
                top1--;
            L[j] = l[top1];
            l[++top1] = j;
        }
        int top2 = 0;
        for(int j = m; j >= 1; j--) {
            while(top2 > 0 && h[r[top2]] >= h[j])
                top2--;
            R[j] = (top2 > 0) ? r[top2] : (m + 1);
            r[++top2] = j;
        }
        for(int j = 1; j <= m; j++)
            ans += 1LL * h[j] * (j - L[j]) * (R[j] - j);
    }
    cout << ans;
    return 0;
}