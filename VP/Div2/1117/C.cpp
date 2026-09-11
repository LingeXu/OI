#include <bits/stdc++.h>
#define N 100010
using namespace std;
int t, n, m;
int dp[N];
bool isnode[N];
vector<int> graph[N], ans;
int dfs(int u) {
    int res = 0;
    if(isnode[u] == 1)  res++;
    for(int v : graph[u]) 
        if(dfs(v) != 0)
            res++;
    return dp[u] = res;
}
void dfs2(int u) {
    vector<int> nx;
    for(int v : graph[u]) {
        if(dp[v] != 0) {
            nx.push_back(v);
            dfs2(v);
        }
    }
    if(!isnode[u]) {
        for(int i = 0; i < (int)nx.size() - 1; i++) {
            ans.push_back(nx[i]);
        }
    }
    else {
        for(int i = 0; i < (int)nx.size(); i++) {
            ans.push_back(nx[i]);
        }
    }
}
void solve() {
    ans.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        graph[i].clear();
        isnode[i] = false;
    }
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        graph[u].push_back(i);
    }
    cin >> m;
    vector<int> node;
    for(int i = 0; i < m; i++) {
        int u;
        cin >> u;
        node.push_back(u);
        isnode[u] = true;
    }
    dfs(1);
    dfs2(1);
    cout << (int)ans.size() << ' ';
    if((int)ans.size() == 0) {
        cout << '\n';
        return;
    }
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}