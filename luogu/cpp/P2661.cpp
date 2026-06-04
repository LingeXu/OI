#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
int n,cnt=0,scc_cnt=0;
int dfn[N],low[N],scc_mem[N],team[N];
bool in_stack[N];
vector<int> g[N];
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    in_stack[u]=true;

    for(int &neighbor:g[u]){
        if(!dfn[neighbor]){
            tarjan(neighbor);
            low[u]=min(low[u],low[neighbor]);
        }
        else if(in_stack[neighbor])
            low[u]=min(low[u],dfn[neighbor]);
    }

    if(dfn[u]==low[u]){
        while(1){
            int x=s.top();
            s.pop();
            team[x]=scc_cnt;
            scc_mem[scc_cnt]++;
            in_stack[x]=false;
            if(x==u)
                break;
        }
        scc_cnt++;
    }
}
int main(){
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        g[i].push_back(x);
    }
    memset(in_stack,0,sizeof(in_stack));
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    sort(scc_mem,scc_mem+scc_cnt);
    for(int i=0;i<scc_cnt;i++){
        if(scc_mem[i]!=1){
            cout<<scc_mem[i];
            return 0;
        }
    }
    return 0;
}