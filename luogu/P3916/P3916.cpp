#include<iostream>
#include<vector>
#include<cstring>
#define N 100010
using namespace std;
vector<int> graph[N];
/*int A(int u){
    int dp=u;
    for(int &neighbor:graph[u]){
        dp=max(dp,A(neighbor));
    }
    return dp;
}*/
int A[N];
bool vis[N];
void dfs(int u){
    vis[u]=true;
    for(int &neighbor:graph[u]){
        if(!vis[neighbor]){
            dfs(neighbor);
            A[u]=max(A[u],A[neighbor]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
    }
    //for(int i=1;i<=n;i++)   cout<<A(i)<<" ";
    for(int i=1;i<=n;i++)    A[i]=i;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    for(int i=1;i<=n;i++)   cout<<A[i]<<" ";
    return 0;
}