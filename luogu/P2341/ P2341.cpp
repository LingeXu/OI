#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<cstring>

#define N 10001
#define M 50001

using namespace std;

vector<int> graph[N];
stack<int> node2vis;
vector<pair<int,int> > g[M];

int cnt;
int scc_cnt;
int dfn[N],low[N];
bool in_stack[N];
int team[N];
int ans;
bool welcomed[N];
int scc_sz[N];
int num;

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
            scc_sz[scc_cnt]++;
            if(x==start)    break;
        }
    }
}

bool cmp(int a,int b){
    return a>b;
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
    memset(scc_sz,0,sizeof(scc_sz));

    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i);
    }

    for(int i=1;i<=scc_cnt;i++) welcomed[i]=true;

    for(int i=1;i<=m;i++)
    {
        if(team[g[i][0].first]==team[g[i][0].second]) continue;

        else    welcomed[team[g[i][0].first]]=false;
    }

    ans=0;
    num=0;

    for(int i=1;i<=scc_cnt;i++)
    {
        if(welcomed[i])
        {
            num++;
            ans+=scc_sz[i];
        }
    }

    if(num==1) 
        printf("%d\n",ans);

    else    printf("0\n");

    return 0;
}