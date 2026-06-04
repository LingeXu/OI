#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define N 1510
using namespace std;
int n,m;
int dist[N];
struct edge{
    int to,val;
};
vector<edge> g[N];
/*void dfs(int u){
    for(auto &e:g[u]){
        dist[e.to]=max(dist[e.to],dist[u]+e.val);
        dfs(e.to);
    }
}*/
void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &e:g[x]){
            if(dist[e.to]<dist[x]+e.val)
            dist[e.to]=dist[x]+e.val;
            q.push(e.to);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    //dfs(1);
    bfs();
    if(dist[n]==0)
        cout<<-1;
    else
        cout<<dist[n];
    return 0;
}