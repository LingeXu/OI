#include <bits/stdc++.h>
#define N 110
using namespace std;
int n, m, ans;
bool has_edge[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(has_edge, 0, sizeof(has_edge));
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        has_edge[a][b] = true;
    }
    for(int i = 1; i <= n; i++)
        has_edge[i][i] = true;
    for(int w = 1; w <= n; w++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                has_edge[u][v] = has_edge[u][v] | (has_edge[u][w] & has_edge[w][v]);
    ans = n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!has_edge[i][j] && !has_edge[j][i]) {
                //cout << i << ' ' << j << '\n';
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}