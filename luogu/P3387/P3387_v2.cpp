#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>

#define N 10001
#define M 100001

using namespace std;

vector<int> graph[N];
stack<int> node2vis;
vector<pair<int,int> > g;
vector<int> dag[N];

int dfn[N],low[N];
int cnt;
bool in_stack[N];
int scc_cnt;
int team[N];
int scc_weight[N];
int a[N];
int dp[N];
int dag_max;
bool vis[N];

void tarjan(int start){
    dfn[start]=low[start]=++cnt;
    node2vis.push(start);
    in_stack[start]=true;

    for(int &neighbor:graph[start])
    {
        if(!dfn[neighbor])
        {
            tarjan(neighbor);
            low[start]=min(low[start],low[neighbor]);
        }

        else if(in_stack[neighbor])
            low[start]=min(low[start],dfn[neighbor]);

        else    continue;
    }

    if(dfn[start]==low[start])
    {
        scc_cnt++;
        while(1){
            int x=node2vis.top();
            node2vis.pop();
            in_stack[x]=false;
            team[x]=scc_cnt;
            scc_weight[scc_cnt]+=a[x];
            if(x==start)    break;
        }
    }
}

void dp_dfs(int start){
    if(vis[start])  return;
    vis[start]=true;

    for(int &neighbor:dag[start])
    {
        if(!vis[neighbor])
            dp_dfs(neighbor);
        
        dp[start]=max(dp[start],dp[neighbor]+scc_weight[start]);
    }

    dag_max=max(dag_max,dp[start]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);

    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        graph[x].push_back(y);
        g.push_back({x,y});
    }

    cnt=0;
    memset(in_stack,0,sizeof(in_stack));
    scc_cnt=0;
    memset(scc_weight,0,sizeof(scc_weight));

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);

    for(auto &edge:g)
    {
        if(team[edge.first]==team[edge.second]) continue;

        else
        {
            dag[team[edge.first]].push_back(team[edge.second]);
        }
    }

    for(int i=1;i<=scc_cnt;i++)
        dp[i]=scc_weight[i];
    
    dag_max=0;
    memset(vis,0,sizeof(vis));

    for(int i=1;i<=scc_cnt;i++)
    {
        if(!vis[i])
            dp_dfs(i);
    }

    printf("%d\n",dag_max);
    return 0;
}