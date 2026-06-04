#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>

#define N 10001
#define M 100001

using namespace std;

vector<int> graph[N],DAG[N];
vector<pair<int,int> > g;
vector<pair<int,int> > dag[N];

int dfn[N];
int low[N];
int t_cnt;
bool in_stack[N];
int scc[N];
int weight[N];
int a[N];
int dp[N];
int cnt;
int dag_cnt=1;

stack<int> node2vis;

void tarjan(int start){
    dfn[start]=low[start]=++t_cnt;
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
        {
            low[start]=min(low[start],dfn[neighbor]);
        }
        else    continue;
    }

    if(dfn[start]==low[start])
    {
        while(1){
            int x=node2vis.top();
            node2vis.pop();
            in_stack[x]=false;
            scc[x]=dag_cnt;
            weight[dag_cnt]+=a[x];

            if(x==start)    break;
        }
        dag_cnt++;
    }
}

int dp_dfs(int start) {
    if (dp[start] > 0) return dp[start];
    dp[start] = weight[start];
    for (int &node : DAG[start]) {
        dp[start] = max(dp[start], dp_dfs(node) + weight[start]);
    }
    return dp[start];
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)    scanf("%d",&a[i]);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        graph[a].push_back(b);
        g.push_back({a,b});
    }

    t_cnt=0;
    memset(in_stack,0,sizeof(in_stack));

    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])  tarjan(i);
    }

   /* for(auto &edge:g)
    {
        if(scc[edge.first]!=scc[edge.second])
        {
            dag[scc[edge.first]].push_back({weight[scc[edge.first]]+weight[scc[edge.first]],scc[edge.second]});
        }
    }



    dp_dfs(1);

    sort(dp,cnt,cmp);

    printf("%d\n",dp[0]);*/

    for(auto &edge:g)
    {
        if(scc[edge.first]==scc[edge.second])   continue;
        
        else    DAG[scc[edge.first]].push_back(scc[edge.second]);
    }

    for(int i=1;i<dag_cnt;i++) dp[i]=weight[i];

    int ans=0;
    for(int i=1;i<dag_cnt;i++)
    {
        ans=max(ans,dp_dfs(i));
    }

    printf("%d\n",ans);
    return 0;
}