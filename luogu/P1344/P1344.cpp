#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>

#define N 33
#define M 1001
#define C 2000001
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int to,rev;
    long long cap;
};

vector<edge> graph[N];

void add_edge(int u,int v,long long w){
    graph[u].push_back({v,(int)graph[v].size(),w});
    graph[v].push_back({u,(int)graph[u].size()-1,0});
}
    
int level[N],iter[N];

bool bfs(int s,int t){
    memset(level,-1,sizeof(level));
    level[s]=0;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto &e:graph[x])
        {
            if(e.cap>0&&level[e.to]==-1)
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

    for(int &i=iter[u];i<graph[u].size();i++)
    {
        edge &e=graph[u][i];
        if(e.cap>0&&level[u]<level[e.to])
        {
            long long d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                graph[e.to][e.rev].cap+=d;
                iter[u]=i;
                return d;
            }
        }
    }

    return 0;
}

long long flow_max(int s,int t){
    long long flow=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));
        long long d;
        while((d=dfs(s,t,INF))>0){
            flow+=d;
        }
    }

    return flow;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);

        add_edge(u,v,w*(m+1)+1);
    }

    long long ans=flow_max(1,n);
    printf("%lld %lld\n",ans/(m+1),ans%(m+1));

    return 0;
}