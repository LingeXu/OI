#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define N 5010
using namespace std;
int n,m,cnt=0;
int in_deg[N],dist[N];
vector<int> g[N];
void Kahn(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            in_deg[g[i][j]]++;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            q.push(i);
            dist[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int &neighbor:g[x]){
            dist[neighbor]=(dist[neighbor]+dist[x])%80112002;
            /*if(g[neighbor].size()==0)
                cnt+=dist[neighbor];*/
            if(--in_deg[neighbor]==0)
                q.push(neighbor);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        g[from].push_back(to);
    }
    memset(dist,0,sizeof(dist));
    Kahn();
    /*for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";*/
    for(int i=1;i<=n;i++)
        if(g[i].size()==0)
            cnt=(cnt+dist[i])%80112002;
    cout<<cnt;
    return 0;
}