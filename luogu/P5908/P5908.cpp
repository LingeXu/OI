#include<iostream>
#include<vector>
#include<cstring>
#define N 100010
using namespace std;
int n, d, ans = 0;
bool vis[N];
vector<int> graph[N];
void add_edge(int a, int b){
    graph[a].push_back(b);
    graph[b].push_back(a);
}
void dfs(int u, int remain){
    if(vis[u])
        return;
    vis[u] = true;
    ans++;
    if(remain == 0)
        return;
    for(int neighbor : graph[u])    
        dfs(neighbor, remain - 1);
}
int main(){
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++){
        int from, to;
        cin >> from >> to;
        add_edge(from, to);
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, d);
    cout << ans - 1;
    return 0;
}