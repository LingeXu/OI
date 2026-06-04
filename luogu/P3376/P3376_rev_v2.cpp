#include<iostream>
#include<vector>
#include<queue>

#define N 201
const long long INF=(1LL<<60);

using namespace std;

int n,m,s,t;
int level[N],iter[N];

struct edge{
    int to,rev;
    long long weight;
};

vector<edge> graph[N];

void add_edge(int u,int v,long long w){
    graph[u].push_back({v,(int)graph[v].size(),w});
    graph[v].push_back({u,(int)graph[u].size()-1,0});
}

bool bfs(int s,int t){
    queue<int> q;
    q.push(s);

    memset(level,-1,sizeof(level));
    level[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto &e:graph[x])
        {
            if(e.weight>0&&level[e.to]==-1)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
            }
        }   
    }

    return level[t]!=-1;
}

long long dfs(int s,int t,long long flow){
    if(s==t)    return flow;
    if(flow==0) return 0;

    for(int &i=iter[s];i<graph[s].size();i++)
    {
        if(graph[s][i].weight>0&&level[s]+1==level[graph[s][i].to])
        {
            long long f=dfs(graph[s][i].to,t,min(flow,graph[s][i].weight));
            if(f>0)
            {
                graph[s][i].weight-=f;
                graph[graph[s][i].to][graph[s][i].rev].weight+=f;
                return f;
            }
        }
    }

    return 0;
}

long long max_flow(int s,int t){
    long long flow=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        long long f;
        while((f=dfs(s,t,INF))>0&&f!=INF)
        {
            flow+=f;
        }
    }

    return flow;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        add_edge(a,b,c);
    }

    printf("%lld\n",max_flow(s,t));

    return 0;
}