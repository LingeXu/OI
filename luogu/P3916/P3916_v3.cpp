#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE<<']'<<#x<<" "<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int n,m,cnt=0;
int scc_cnt=0;
int dfn[N],low[N],team[N],scc_max[N],in[N],ans[N];
bool in_stack[N];
vector<int> rev_g[N],rev_graph[N];
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    in_stack[u]=true;

    for(int &neighbor:rev_g[u]){
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
            in_stack[x]=false;
            team[x]=scc_cnt;
            scc_max[scc_cnt]=max(scc_max[scc_cnt],x);
            if(x==u)
                break;
        }
        scc_cnt++;
    }
}
void build_dag(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<rev_g[i].size();j++)
            if(team[i]!=team[rev_g[i][j]]&&count(rev_graph[team[i]].begin(),rev_graph[team[i]].end(),team[rev_g[i][j]])==0)
                rev_graph[team[i]].push_back(team[rev_g[i][j]]);
}
void Kahn(){
    memset(in,0,sizeof(in));
    for(int i=0;i<scc_cnt;i++){
        for(int j=0;j<rev_graph[i].size();j++){
            in[rev_graph[i][j]]++;
        }   
    }
    queue<int> q;
    for(int i=0;i<scc_cnt;i++)
        if(in[i]==0)
            q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int &neighbor:rev_graph[x]){
            ans[neighbor]=max(ans[neighbor],ans[x]);
            if(--in[neighbor]==0)
                q.push(neighbor);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        rev_g[to].push_back(from);
    }
    for(int i=1;i<=n;i++)
        if(dfn[i]==0)
            tarjan(i);
    //cout<<scc_cnt<<'\n';
    //for(int i=0;i<scc_cnt;i++)  cout<<scc_max[i]<<" ";
    //cout<<'\n';
    for(int i=0;i<scc_cnt;i++)  ans[i]=scc_max[i];
    build_dag();
    Kahn();
    for(int i=1;i<=n;i++)
        cout<<ans[team[i]]<<" ";
    return 0;
}