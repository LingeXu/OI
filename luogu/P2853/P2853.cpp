#include<iostream>
#include<vector>
#include<queue> 
#include<algorithm>
#include<cstring>
#define K 1010
#define N 1010
using namespace std;
int k,n,m;
int cow_node[K];
bool vis[N],IsAvailable[N];
vector<int> g[N];
void bfs(int u){
    queue<int> q;
    q.push(u);
    memset(vis,0,sizeof(vis));
    vis[u]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int neighbor:g[x]){
            if(!vis[neighbor]){
                vis[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
}
void judge(){
    for(int i=1;i<=n;i++)   IsAvailable[i]*=vis[i];
}
int main(){
    cin>>k>>n>>m;
    for(int i=0;i<k;i++)   cin>>cow_node[i];
    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        g[from].push_back(to);
    }
    for(int i=1;i<=n;i++)   IsAvailable[i]=1;
    /*for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            cout<<i<<" "<<g[i][j]<<'\n';*/
    for(int i=0;i<k;i++){
        bfs(cow_node[i]);
        judge();
    }
    /*bfs(2);
    judge();*/
    cout<<count(IsAvailable+1,IsAvailable+n+1,true)<<'\n';
    /*for(int i=1;i<=n;i++)
        cout<<IsAvailable[i]<<" ";*/
    return 0;
}