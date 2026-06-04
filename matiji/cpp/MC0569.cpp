#include <bits/stdc++.h>
#define N 1010
#define M 1010
using namespace std;
int n, m, t1, t2, ans = 0;
int g[N][M];
int main() {
    cin >> n >> m >> t1 >> t2;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    int rows = n / t1;
    int cols = m / t2;
    for(int i = 1; i <= rows * cols; i++) {
        int sum = 0;
        for(int x = (i - 1) / cols * t1 + 1; x <= ((i - 1) / cols + 1) * t1; x++) {
            for(int y = (i % cols != 0 ? i % cols - 1 : cols - 1) * t2 + 1; y <= (i % cols != 0 ? i % cols : cols) * t2; y++) {
                sum ^= g[x][y];
            }
        }
        ans += sum;
    }
    cout << ans;
    return 0;
}