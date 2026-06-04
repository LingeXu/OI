#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 51
#define INF 0x3f3f3f3f

using namespace std;

int n;
int dist[2*N+2],prevv[2*N+2],preve[2*N+2];
bool inq[2*N+2];

struct edge{
    int to,rev,cap,cost;
};

vector<edge> graph[2*N+2],g[2*N+2];

void add_edge(int a,int b,int c,int d){
    graph[a].push_back({b,(int)graph[b].size(),c,d});
    graph[b].push_back({a,(int)graph[a].size()-1,0,-d});
}

bool spfa(int s,int t){
    queue<int> q;
    q.push(s);

    memset(inq,0,sizeof(inq));
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

    return dist[t]!=INF;
}

int min_cost_max_flow(int s,int t){
    int maxf=0,minc=0;

    while(spfa(s,t)){
        int flow=INF;
        for(int i=t;i!=s;i=prevv[i])
            flow=min(flow,graph[prevv[i]][preve[i]].cap);
        
        maxf+=flow;
        minc+=flow*dist[t];

        for(int i=t;i!=s;i=prevv[i])
        {
            edge &e=graph[prevv[i]][preve[i]];
            e.cap-=flow;
            graph[e.to][e.rev].cap+=flow;
        }
    }

    return minc;
}

int main(){
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;

            add_edge(i,j+n,1,x);
        }
    }

    for(int i=1;i<=n;i++)
    {
        add_edge(0,i,1,0);
        add_edge(n+i,2*n+1,1,0);
    }

    for(int i=0;i<=2*n+1;i++)
    {
        //g[i].clear();

        for(int j=0;j<graph[i].size();j++)
        {
           edge e=graph[i][j];
           e.cost=-e.cost;
           g[i].push_back(e);
        }
    }

    cout<<min_cost_max_flow(0,2*n+1)<<endl;

    for(int i=0;i<=2*n+1;i++)
        for(int j=0;j<graph[i].size();j++)
            graph[i][j]=g[i][j];
            
    cout<<-min_cost_max_flow(0,2*n+1)<<endl;

    return 0;
}