#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define M 101
#define N 101
#define INF 0x3f3f3f3f

using namespace std;

int m,n;
int level[N+2],iter[N+2];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[N+2];

void add_edge(int a,int b,int c){
    graph[a].push_back({b,(int)graph[b].size(),c});
    graph[b].push_back({a,(int)graph[a].size()-1,0});
}

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

int dfs(int u,int t,int f){
    if(u==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[u];i<graph[u].size();i++)
    {
        edge &e=graph[u][i];

        if(e.cap>0&&level[e.to]==level[u]+1)
        {
            int d=dfs(e.to,t,min(f,e.cap));

            if(d>0)
            {
                e.cap-=d;
                graph[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }

    return 0;
}

int max_flow(int s,int t){
    int maxf=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        int flow=dfs(s,t,INF);

        while(flow>0){
            maxf+=flow;
            flow=dfs(s,t,INF);
        }
    }

    return maxf;
}

int main(){
    cin>>m>>n;

    while(1){
        int x,y;
        cin>>x>>y;

        if(x==-1&&y==-1)
            break;

        add_edge(x,y,1);
    }

    for(int i=1;i<=m;i++)
        add_edge(0,i,1);

    for(int i=m+1;i<=n;i++)
        add_edge(i,n+1,1);

    cout<<max_flow(0,n+1)<<endl;

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            edge &e=graph[i][j];

            if(e.cap==0&&e.to!=0)
                cout<<i<<" "<<e.to<<endl;
        }
    }

    return 0;
}