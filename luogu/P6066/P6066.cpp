#include <bits/stdc++.h>
#define N 10010
#define M 50050
using namespace std;
int n, m;
bool used[2 * M];
//int has_edge[N][N];
//map< pair<int, int>, int> mp;
vector< pair<int, int> > graph[N];
vector<int> ans;
void dfs(int u) {
    for(auto& e : graph[u]) {
        if(!used[e.second]) {
            used[e.second] = true;
            dfs(e.first);
        }
    }
    ans.push_back(u);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i + m});
        /*has_edge[u][v]++;
        has_edge[v][u]++;*/
        /*mp[make_pair(u, v)]++;
        mp[make_pair(v, u)]++;*/
    }
    dfs(1);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}