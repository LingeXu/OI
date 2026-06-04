#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define N 1010
#define M 1010
using namespace std;
int n,m,s,newnode;
int in_deg[N+M],dist[N+M];
bool is_station[N+M];
vector<int> g[N+M];
int Kahn(){
    /*cout<<start<<" "<<end<<'\n';
    for(int i=start;i<=end;i++)
        for(int j=0;j<g[i].size();j++)
            cout<<i<<" "<<g[i][j]<<'\n';*/
    for(int i=1;i<=newnode;i++)
        for(int j=0;j<g[i].size();j++)
            in_deg[g[i][j]]++;
    queue<int> q;
    for(int i=1;i<=newnode;i++)
        if(in_deg[i]==0)
            q.push(i);
    memset(dist,0,sizeof(dist));
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int neighbor:g[x]){
            dist[neighbor]=max(dist[neighbor],dist[x]+1);
            if(--in_deg[neighbor]==0)
                q.push(neighbor);
        }
    }
    int max_dist=0;
    for(int i=1;i<=newnode;i++)
        if(dist[i]>max_dist)
            max_dist=dist[i];
    return max_dist/2+1;
}

int main(){
    cin>>n>>m;
    //memset(has_edge,0,sizeof(has_edge));
    for(int i=1;i<=m;i++){
        memset(is_station,0,sizeof(is_station));
        cin>>s;
        int start,end,x;
        for(int i=1;i<=s;i++){
            cin>>x;
            is_station[x]=true;
            if(i==1)
                start=x;
            if(i==s)
                end=x;
        }
        newnode=++n;
        for(int i=start;i<=end;i++){
            if(is_station[i])
                g[newnode].push_back(i);
            else
                g[i].push_back(newnode);
        }
    }
    cout<<Kahn();
    return 0;
}