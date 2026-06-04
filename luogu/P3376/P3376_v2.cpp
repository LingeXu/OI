#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>

#define N 201
#define M 5001
const long long INF=1e18;

using namespace std;

int level[N],iter[N];

struct edge{
    int to,rev;
    long long weight;
};
vector<edge> g[N];

void add_edge(int u,int v,long long w){
    g[u].push_back({v,(int)g[v].size(),w});
    g[v].push_back({u,(int)g[u].size()-1,0});
}   

bool bfs(int s,int t){
    memset(level,-1,sizeof(level));

    level[s]=0;

    queue<int> q;

    q.push(s);

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto &e:g[x])
        {
            if(e.weight>0&&level[e.to]<0)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
            }
        }
    }

    return level[t]!=-1;
}

long long dfs(int u,int t,long long f){
    if(u==t)    return f;
    for(int &i=iter[u];i<g[u].size();i++)
    {
        edge &e=g[u][i];
        if(e.weight>0&&level[e.to]>level[u])
        {
            long long d=dfs(e.to,t,min(f,e.weight));
            if(d>0)
            {
                e.weight-=d;
                g[e.to][e.rev].weight+=d;
                return d;
            }
        }
    }

    return 0;
}

long long max_flow(int s,int t){
    long long flow=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));
        long long d;
        while((d=dfs(s,t,INF))>0)    flow+=d;
    }

    return flow;
}

int main(){
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);

        add_edge(a,b,c);
    }


    printf("%lld\n",max_flow(s,t));

    return 0;
}