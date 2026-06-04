#include<iostream>
#include<vector>
#include<stack>

#define N 10001
#define M 100001

using namespace std;

int n,m,cnt,scc_cnt,maxval;
int a[N],dfn[N],low[N],team[N],scc_weight[N],dp[N];
bool instack[N],vis[N],has_edge[N][N];

vector<int> graph[N],g[N];
stack<int> s;

void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    instack[u]=true;

    for(int &to:graph[u])
    {
        if(!dfn[to])
        {
            tarjan(to);
            low[u]=min(low[u],low[to]);
        }

        else if(instack[to])
        {
            low[u]=min(low[u],dfn[to]);
        }
    }

    if(dfn[u]==low[u])
    {
        while(1){
            int x=s.top();
            s.pop();
            instack[x]=false;

            team[x]=scc_cnt;
            scc_weight[scc_cnt]+=a[x];

            if(x==u)
            {
                scc_cnt++;
                break;
            }  
        }
    }
}

void dfs(int u){
    dp[u]=scc_weight[u];

    vis[u]=true;

    for(int &to:g[u])
    {
        if(!vis[to])
            dfs(to);
        
        dp[u]=max(dp[u],dp[to]+scc_weight[u]);
    }

    maxval=max(maxval,dp[u]);
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
    }

    cnt=0;
    scc_cnt=1;

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    
    scc_cnt--;

    for(int i=1;i<=n;i++)
        for(int j=0;j<graph[i].size();j++)
        {
            if(team[i]==team[graph[i][j]])  continue;
            else if(team[i]!=team[graph[i][j]]&&!has_edge[team[i]][team[graph[i][j]]])
            {
                g[team[i]].push_back(team[graph[i][j]]);    
                has_edge[team[i]][team[graph[i][j]]]=true;    
            }  
        }

    maxval=0;

    for(int i=1;i<=scc_cnt;i++)
        dfs(i);

    cout<<maxval<<endl;

    return 0;
}