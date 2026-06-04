#include <bits/stdc++.h>
#define N 1010
#define X 1010
typedef long long ll;
using namespace std;
int n, x;
ll dp[N][X];
struct inf{
    int l, w, u;
}f[N];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++)  cin >> f[i].l >> f[i].w >> f[i].u;
    for(int i = 0; i <= x; i++){
        if(i >= f[0].u)
            dp[0][i] = f[0].w;
        else    dp[0][i] = f[0].l;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(j - f[i].u >= 0)
                dp[i][j] = 1LL * max(dp[i - 1][j] + f[i].l, dp[i - 1][j - f[i].u] + f[i].w);
            else    dp[i][j] = dp[i - 1][j] + f[i].l;
        }
    }
    cout << 5 * dp[n - 1][x];
    return 0;
}