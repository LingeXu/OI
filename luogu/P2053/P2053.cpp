#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define M 10
#define N 61
#define T 1001
#define INF 0x3f3f3f3f

using namespace std;

int m,n;
int dist[N+N*M+2],prevv[N+N*M+2],preve[N+N*M+2];
bool inq[N+N*M+2];

struct edge{
    int to,rev,cap,cost;
};

vector<edge> graph[N+N*M+2];


void add_edge(int a,int b,int c,int d){
    graph[a].push_back({b,(int)graph[b].size(),c,d});
    graph[b].push_back({a,(int)graph[a].size()-1,0,-d});
}

bool spfa(int s,int t){
    queue<int> q;
    q.push(s);
    inq[s]=true;

    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;

        for(int i=0;i<graph[x].size();i++)
        {
            edge &e=graph[x][i];

            if(e.cap>0&&dist[e.to]>dist[x]+e.cost)
            {
                dist[e.to]=dist[x]+e.cost;
                prevv[e.to]=x;
                preve[e.to]=i;

                if(!inq[e.to])
                {
                    q.push(e.to);
                    inq[e.to]=true;
                }
            }
        }
    }

    return dist[t]<INF;
}

double min_cost_max_flow(int s,int t){
    double flow=0,cost=0;
    while(spfa(s,t)){
        int f=INF;
        for(int i=t;i!=s;i=prevv[i])
            f=min(f,graph[prevv[i]][preve[i]].cap);

        flow+=f;
        cost+=f*dist[t];

        for(int i=t;i!=s;i=prevv[i])
        {
            edge &e=graph[prevv[i]][preve[i]];
            e.cap-=f;
            graph[i][e.rev].cap+=f;
        }
    }

    return cost;
}

int main(){
    cin>>m>>n;

    for(int i=1;i<=n;i++)
    {
        add_edge(0,i,1,0);

        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;

            for(int k=1;k<=n;k++)
                add_edge(i,n+(j-1)*n+k,1,k*x);
        }
    }

    for(int j=1;j<=m;j++)
        for(int k=1;k<=n;k++)
            add_edge(n+(j-1)*n+k,n+n*m+1,1,0);

    printf("%.2f\n",min_cost_max_flow(0,n+n*m+1)/n);

    //printf("%d\n",min_cost_max_flow(0,n+n*m+1));
    
    return 0;
}