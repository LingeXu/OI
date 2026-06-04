#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>

#define N 10001
#define M 50001

using namespace std;

vector<int> graph[N],dag[N];
stack<int> node2vis;
vector<pair<int,int> > g[M];

int cnt;
int scc_cnt;
int dfn[N],low[N];
bool in_stack[N];
int team[N];
int ans;
int dp[N];
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
    }

    if(dfn[start]==low[start])
    {
        scc_cnt++;
        while(true)
        {
            int x=node2vis.top();
            node2vis.pop();
            in_stack[x]=false;
            team[x]=scc_cnt;
            if(x==start)    break;
        }
    }
}

void dfs(int start){
    for(int &neighbor:dag[start])
    {
        if(!vis[neighbor])  dfs(neighbor);

        dp[start]+=dp[neighbor];
    }

    ans=max(ans,dp[start]);

    vis[start]=true;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        graph[a].push_back(b);
        g[i].push_back({a,b});
    }

    cnt=0;
    scc_cnt=0;

    for(int i=1;i<=m;i++)
    {
        if(team[g[i][0].first]==team[g[i][0].second]) continue;

        else
            dag[team[g[i][0].first]].push_back(team[g[i][0].second]);
    }

    ans=0;
    memset(dp,1,sizeof(dp));

    for(int i=1;i<=scc_cnt;i++)
    {
        if(!vis[i]) dfs(i);
    }

    printf("%d\n",ans);

    return 0;
}