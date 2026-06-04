#include<iostream>
#include<vector>
#define N 1010
using namespace std;
int n,start;
int in_deg[N],out_deg[N],deg[N];
bool vis[N];
struct WordNode{
    char begin,end;
    string word;
}w[N];
vector<int> g[N];
void build(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(w[i].begin==w[j].end)
                g[j].push_back(i);
            if(w[i].end==w[j].begin)
                g[i].push_back(j);
        }
    }
}
void in_deg_count(){
    memset(in_deg,0,sizeof(in_deg));
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            in_deg[g[i][j]]++;
}
void out_deg_count(){
    memset(out_deg,0,sizeof(out_deg));
    for(int i=1;i<=n;i++)
        out_deg[i]=g[i].size();
}
void deg_count(){
    for(int i=0;i<n;i++)
        deg[i]=in_deg[i]-out_deg[i];
}
void judge(){
    bool entry,circuit;
    entry=count(deg,deg+n,0)==n-2&&count(deg,deg+n,-1)==1&&count(deg,deg+n,1)==1;
    circuit=count(deg,deg+n,0)==n;
    if(!(entry||circuit)){
        cout<<"***";
        return;
    }
    if(entry)
        ProcessEntry();
    else if(circuit)
        ProcessCircuit();
}
void ProcessEntry(){
    for(int i=1;i<=n;i++)
        if(deg[i]==-1)
            start=i;
}
void ProcessCircuit(){
    string maxw="a";
    for(int i=1;i<=n;i++){
        if(w[i].word>maxw){
            maxw=w[i].word;
            start=i;
        }
    }
}
vector<int> dfs(int u){
    if()
    vector<int> route;
    vis[u]=true;
    for(int neighbor:g[u]){
        vector<int> ForeRoute=dfs(neighbor);
    }
}
int main(){
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        w[i].begin=s[0];
        w[i].end=s.back();
        w[i].word=s;
    }
    build();
    in_deg_count();
    out_deg_count();
    deg_count();
    judge();
    return 0;
}