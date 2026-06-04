#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 33
#define INF 0x3f3f3f3f

using namespace std;

int n,m;
int level[N],iter[N];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[N];

void add_edge(int a,int b,int c){
    graph[a].push_back({b,(int)graph[b].size(),c});
    graph[b].push_back({a,(int)graph[a].size()-1,0});
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
            if(e.cap>0&&level[e.to]==-1)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
            }
        }
    }

    return level[t]!=-1;
}

int dfs(int s,int t,int flow){
    if(s==t)    return flow;

    for(int &i=iter[s];i<graph[s].size();i++)
    {
        edge &e=graph[s][i];
        if(level[e.to]==level[s]+1&&e.cap>0)
        {   
            int f=dfs(e.to,t,min(flow,e.cap));
            if(f>0)
            {
                e.cap-=f;
                graph[e.to][e.rev].cap+=f;
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

        int f=dfs(s,t,INF);
        while(f>0){
            flow+=f;
            f=dfs(s,t,INF);
        }
    }

    return flow;
}

int main(){
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        add_edge(a,b,c*(m+1)+1);
    }

    long long maxflow=max_flow(1,n);
    printf("%lld %lld\n",maxflow/(m+1),maxflow%(m+1));

    return 0;
}