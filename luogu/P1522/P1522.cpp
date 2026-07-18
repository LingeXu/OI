#include <bits/stdc++.h>
#define N 155
#define INF 0x3f3f3f3f
using namespace std;
int n, idx = 0;
double ans = INF;
int team[N];
char has_edge[N][N];
double diametre[N], farthest[N], d[N][N];
struct location {
    double x, y;
} node[N];   
vector< pair<double, int> > graph[N];
double GetDis(int id1, int id2) {
    double x1 = node[id1].x;
    double x2 = node[id2].x;
    double y1 = node[id1].y;
    double y2 = node[id2].y;
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
void dfs(int u, int idx) {
    if(team[u] != -1)   return;
    team[u] = idx;
    for(auto node : graph[u])
        dfs(node.second, idx);
}
void floyd() {
    for(int w = 0; w < n; w++)
        for(int u = 0; u < n; u++)
            for(int v = 0; v < n; v++)
                d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> node[i].x >> node[i].y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = ((i == j) ? 0 : 1e10);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> has_edge[i][j];
            if(has_edge[i][j] == '1') {
                double dist = GetDis(i, j);
                graph[i].push_back({dist, j});
                d[i][j] = dist;
            }
        }
    }
    memset(team, -1, sizeof(team));
    for(int i = 0; i < n; i++)
        if(team[i] == - 1)
            dfs(i, ++idx);
    floyd();

    /*for(int i = 0; i < n; i++)
        cout << team[i] << ' ';

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            cout << i << ' ' << j << ' ' << d[i][j] << '\n';*/

    memset(diametre, 0, sizeof(diametre));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(team[i] == team[j]) {
                farthest[i] = max(farthest[i], d[i][j]);
                diametre[team[i]] = max(diametre[team[i]], d[i][j]);
            }
        }
    }   
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(team[i] != team[j])
                ans = min(ans, max(farthest[i] + farthest[j] + GetDis(i, j), max(diametre[team[i]], diametre[team[j]])));
    cout << fixed << setprecision(6) << ans;
    return 0;
}