#include <bits/stdc++.h>
#define N 5050
using namespace std;
int n, m;
int dist1[N][N], dist2[N][N];
vector< pair<int, int> > g1[N], g2[N];
void floyd() {
    memset(dist1, -0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));
    for(int w = 1; w <= n; w++) {
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                dist1[u][v] = max(dist1[u][v], dist1[u][w] + dist1[w][v]);
                dist2[u][v] = min(dist2[u][v], dist2[u][w] + dist2[w][v]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 3) {
            g1[a].push_back({0, b});
            g1[b].push_back({0, a});
            g2[a].push_back({0, b});
            g2[b].push_back({0, a});
        }
        else if(op == 1) {
            int c;
            cin >> c;
            g1[a].push_back({c, b});
        }
        else if(op == 2) {
            int c;
            cin >> c;
            g2[a].push_back({c, b});
        }
    }
    floyd();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist1[i][j] > dist2[i][j] || (dist1[i][j] > 0 && dist1[j][i] > 0)) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}