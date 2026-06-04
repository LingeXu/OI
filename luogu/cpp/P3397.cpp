#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, m;
int d[N][N], ans[N][N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j <= x2; j++) {
            d[j][y1]++;
            d[j][y2 + 1]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans[i][j] = ans[i][j - 1] + d[i][j];
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}