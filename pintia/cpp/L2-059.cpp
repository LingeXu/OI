#include<iostream>
#include<vector>
#include<queue>
#define N 100010
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int, int> > graph[N];
vector<int> g[N];
int max_val = INF, dfs_ans;
int dfs(int u){
    if(graph[u].size() == 0){
        g[u].push_back(u);
        return INF;
    }
    int ans = -1;
    for(auto &e : graph[u]){
        int now = min(e.first, dfs(e.second));
        if(now > ans){
            ans = now;
            g[u] = g[e.second];
        }
        else if(now == ans)
            g[u].insert(g[u].end(), g[e.second].begin(), g[e.second].end());
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int from, val;
        cin >> from >> val;
        graph[from].push_back({val, i});
    }
    cout << dfs(0) << '\n';
    sort(g[0].begin(), g[0].end());
    auto it=unique(g[0].begin(), g[0].end());
    g[0].erase(it, g[0].end());
    cout << g[0][0];
    for(int i = 1; i < (int)g[0].size(); i++)
        cout << " " << g[0][i];
    return 0;
}