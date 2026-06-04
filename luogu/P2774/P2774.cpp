#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 101
#define M 101

#define INF 1e9

using namespace std;

int m,n;
int a[M][N],level[N*M+2],iter[N*M+2];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[N*M+2];

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

int dfs(int u,int t,int f){
    if(u==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[u];i<graph[u].size();i++)
    {
        edge &e=graph[u][i];

        if(e.cap>0&&level[e.to]==level[u]+1)
        {
            int flow=dfs(e.to,t,min(f,e.cap));
            if(flow>0)
            {
                e.cap-=flow;
                graph[e.to][e.rev].cap+=flow;
                return flow;
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

    int sum=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];

            sum+=a[i][j];

            if((i+j)%2==0)
            {
                add_edge(0,(i-1)*n+j,a[i][j]);

                if(i+1<=m)
                    add_edge((i-1)*n+j,i*n+j,INF);
                if(j+1<=n)
                    add_edge((i-1)*n+j,(i-1)*n+j+1,INF);
                if(i-1>=1)
                    add_edge((i-1)*n+j,(i-2)*n+j,INF);
                if(j-1>=1)
                    add_edge((i-1)*n+j,(i-1)*n+j-1,INF);
            }

            else
                add_edge((i-1)*n+j,m*n+1,a[i][j]);
        }
    }

    cout<<sum-max_flow(0,m*n+1)<<endl;

    return 0;
}