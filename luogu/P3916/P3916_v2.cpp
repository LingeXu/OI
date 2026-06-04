#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define N 100010
using namespace std;
vector<int> graph[N],g[N];
stack<int> s;
int cnt=0;
int dfn[N],low[N];
int scc_cnt=0,scc_max[N],team[N];
int A[N],rev_A[N];
bool in_stack[N],vis[N],rev_vis[N],in_queue[N];
void tarjan(int u){
    s.push(u);
    in_stack[u]=true;
    dfn[u]=low[u]=++cnt;
    for(int &neighbor:graph[u]){
        if(!dfn[neighbor]){
            tarjan(neighbor);
            low[u]=min(low[u],low[neighbor]);
        }
        else if(in_stack[neighbor]){
            low[u]=min(low[u],dfn[neighbor]);
        }
    }

    if(low[u]==dfn[u]){
        while(1){
            int x=s.top();
            s.pop();
            in_stack[x]=false;
            team[x]=scc_cnt;
            if(x>scc_max[scc_cnt])
                scc_max[scc_cnt]=x;
            if(x==u)
                break;
        }
        scc_cnt++;
    }
}
/*void dfs(int u){
    vis[u]=true;
    for(int &neighbor:g[u]){
        if(!vis[neighbor]){
            dfs(neighbor);
            A[u]=max(A[u],A[neighbor]);
        }
    }
}*/
/*void rev_dfs(int u){
    rev_vis[u]=true;
    for(int &neighbor:g[u]){
        if(!rev_vis[neighbor]){
            rev_dfs(neighbor);
            rev_A[neighbor]=max(rev_A[neighbor],scc_max[u]);
        }
    }
}*/
void rev_bfs(int u){
    queue<int> q;
    q.push(u);
    in_queue[u]=true;
    rev_vis[u]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        rev_vis[x]=true;
        for(int &neighbor:g[x]){
            if(!in_queue[neighbor]){
                rev_A[neighbor]=max(rev_A[neighbor],rev_A[x]);
                q.push(neighbor);
            }
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
    memset(scc_max,0,sizeof(scc_max));
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    //cout<<scc_cnt<<'\n';
    /*for(int i=1;i<=n;i++)
        cout<<team[i]<<" ";
    cout<<'\n';*/
    for(int i=1;i<=n;i++){
        for(int j=0;j<graph[i].size();j++){
            int from=i,to=graph[i][j];
            if(team[from]!=team[to]&&count(g[team[from]].begin(),g[team[from]].end(),team[to])==0){
                g[team[to]].push_back(team[from]);
                //cout<<team[to]<<" "<<team[from]<<'\n';
            }
        }
    }
    /*for(int i=0;i<scc_cnt;i++)
        for(int j=0;j<g[i].size();j++)
            cout<<i<<" "<<g[i][j]<<" ";
    for(int i=0;i<scc_cnt;i++)
        cout<<scc_max[i]<<" ";*/
    for(int i=0;i<scc_cnt;i++){
        vis[i]=false;
        rev_vis[i]=false;
        A[i]=scc_max[i];
        rev_A[i]=scc_max[i];
    }
    for(int i=0;i<scc_cnt;i++)
        if(!rev_vis[i])
            rev_bfs(i);
    for(int i=1;i<=n;i++)
        cout<<rev_A[team[i]]<<" ";   
    return 0;
}