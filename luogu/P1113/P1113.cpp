#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define N 10010
using namespace std;
int n;
int dist[N],in_deg[N];
bool vis[N];
struct edge{
    int val,to;
};
vector<edge> g[N];

/*void dfs(int u){
    for(auto &e:g[u]){
        if(dist[e.to]==0){
            dfs(e.to);
            dist[u]=max(dist[u],dist[e.to]+e.val);
        }
    }
}*/

void Kahn(){
    for(int i=0;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            in_deg[g[i][j].to]++;
    queue<int> q;
    for(int i=0;i<=n;i++)
        if(in_deg[i]==0)
            q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &e:g[x]){
            dist[e.to]=max(dist[e.to],dist[x]+e.val);
            if(--in_deg[e.to]==0)
                q.push(e.to);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int now,len;
        cin>>now>>len;
        int last;
        while(1){
            cin>>last;
            if(last==0)
                break;
            g[last].push_back({len,i});
        }
        if(i==1)
            g[0].push_back({len,1});
    }
    /*for(int i=0;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            cout<<i<<" "<<g[i][j].to<<" "<<g[i][j].val<<'\n';*/
    memset(dist,0,sizeof(dist));
    Kahn();
    //dfs(n);
    sort(dist,dist+n+1);
    cout<<dist[n];
    return 0;
}