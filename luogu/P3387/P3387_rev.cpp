#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstring>

#define N 10001
#define M 100001

using namespace std;

int n,m,dag_max;
int cnt,team_cnt;
int a[N],dfn[N],low[N],team[N],weight[N],dp[N];
bool in_stack1[N],vis[N];

stack<int> node2vis;

vector<int> graph[N];
vector<int> dag[N];

void tarjan(int u){
    dfn[u]=low[u]=++cnt;

    node2vis.push(u);
    in_stack1[u]=true;

    for(int &neighbor:graph[u])
    {
        if(!dfn[neighbor])
        {
            tarjan(neighbor);
            low[u]=min(low[u],low[neighbor]);
        }

        else if(in_stack1[neighbor])    low[u]=min(low[u],dfn[neighbor]);
    }

    if(dfn[u]==low[u])
    {
        team_cnt++;
        while(1){
            int x=node2vis.top();
            node2vis.pop();
            in_stack1[x]=false;
            team[x]=team_cnt;
            weight[team_cnt]+=a[x];
            
            if(x==u)    break;
        }
    }
}

void build(){
    for(int i=1;i<=n;i++)
    {
        for(int &to:graph[i])
        {
            if(team[i]==team[to])   continue;

            else    dag[team[i]].push_back(team[to]);
        }
    }
}

void dfs(int u){
    dp[u]=weight[u];

    vis[u]=true;

    for(int &to:dag[u])
    {
        if(!vis[to])
        {
            dfs(to);
        }
        dp[u]=max(dp[u],dp[to]+weight[u]);
    }

    dag_max=max(dag_max,dp[u]);
}


int main(){
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);

        graph[u].push_back(v);
    }

    cnt=0,team_cnt=0,dag_max=0;

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    
    build();

    for(int i=1;i<=team_cnt;i++)    dfs(i);
    
    printf("%d\n",dag_max);

    return 0;
}