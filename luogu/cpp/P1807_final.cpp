#include<iostream>
#include<vector>
#define N 1510
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int dist[N];
bool vis[N];
struct edge{
    int to,val;
};
vector<edge> g[N];
int dfs(int u){
    if(u==n)    return 0;
    if(vis[u])  return dist[u];
    vis[u]=true;
    dist[u]=-INF;
    for(auto &e:g[u]){
        int d=dfs(e.to);
        if(d!=-INF)
            dist[u]=max(dist[u],d+e.val);
    }
    return dist[u];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int ans=dfs(1);
    if(ans!=-INF)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}