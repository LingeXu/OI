#include <bits/stdc++.h>
#define N 1010
#define M 1010
using namespace std;
int n, m;
char c[N][M];
bool vis[N][M];
vector<int> pos[N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == 'R')
                pos[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(c[i][j] == 'F') {
                int col_end = m;
                for(int row_end = i; row_end <= n; row_end++) {
                    auto limit = lower_bound(pos[row_end].begin(), pos[row_end].end(), j);
                    if(limit == pos[row_end].end())
                        col_end = min(col_end, m);
                    else    col_end = min(col_end, *lower_bound(pos[row_end].begin(), pos[row_end].end(), j) - 1);
                    ans = max(ans, (row_end - i + 1) * (col_end - j + 1));
                }
            }
        }
    }
    cout << 3 * ans;
    return 0;
}