#include <bits/stdc++.h>
#define N 1010
#define M 1010
typedef long long ll;
using namespace std;
int n, m, c;
int v[N][M];
ll s[N][M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
            s[i][j] = 1LL * v[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int x, y;
    ll max_s = 0;
    for(int i = c; i <= n; i++) {
        for(int j = c; j <= m; j++) {
            ll now_s = 1LL * (s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c]);
            if(now_s > max_s) {
                max_s = now_s;
                x = i;
                y = j;
            }
        }
    }
    cout << x - c + 1 << ' ' << y - c + 1;
    return 0;
}