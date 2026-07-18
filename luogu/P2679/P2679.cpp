#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
#define N 1010
#define M 220
#define K 220
typedef long long ll;
using namespace std;
int n, m, k;
string a, b;
ll dp[2][M][K][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> a >> b;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= m; y++) {
            for(int z = 1; z <= k; z++) {
                dp[x % 2][y][z][0] = (dp[(x - 1) % 2][y][z][0] + dp[(x - 1) % 2][y][z][1]) % MOD;
                if(a[x - 1] == b[y - 1]) 
                    dp[x % 2][y][z][1] = (dp[(x - 1) % 2][y - 1][z - 1][0] + dp[(x - 1) % 2][y - 1][z - 1][1] + dp[(x - 1) % 2][y - 1][z][1]) % MOD;
                else    dp[x % 2][y][z][1] = 0;    
            }
        }
    }
    cout << (dp[n % 2][m][k][0] + dp[n % 2][m][k][1]) % MOD;
    return 0;
}