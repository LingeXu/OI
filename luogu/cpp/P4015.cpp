#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 101
#define M 101
#define INF 0x3f3f3f3f

using namespace std;

int m,n;
int dist[M+N+2],prevv[M+N+2],preve[M+N+2];
bool inq[M+N+2];

struct edge{
    int to,rev,cap,cost;
};

vector<edge> graph[M+N+2];

void add_edge(int a,int b,int c,int d){
    graph[a].push_back({b,(int)graph[b].size(),c,d});
    graph[b].push_back({a,(int)graph[a].size()-1,0,-d});
}

bool spfa(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;

    queue<int> q;
    q.push(s);
    memset(inq,0,sizeof(inq));
    inq[s]=true;

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
        {   
            edge &e=graph[prevv[i]][preve[i]];
            flow=min(flow,e.cap);
        }

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
    cin>>m>>n;

    vector<int> a(m+1),b(n+1);
    vector<vector<int>> c(m + 1, vector<int>(n + 1));

    for(int i=1;i<=m;i++)
    {
        cin>>a[i];

        add_edge(0,i,a[i],0);
    }

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];

        add_edge(m+i,m+n+1,b[i],0);
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];

            add_edge(i,m+j,INF,c[i][j]);
        }
    }

    cout<<min_cost_max_flow(0,m+n+1)<<endl;

    for(int i=0;i<=m+n+1;i++)
        graph[i].clear();

    for(int i=1;i<=m;i++)
        add_edge(0,i,a[i],0);

    for(int i=1;i<=n;i++)
        add_edge(m+i,m+n+1,b[i],0);

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            add_edge(i,m+j,INF,-c[i][j]);

    cout<<-1*min_cost_max_flow(0,m+n+1)<<endl;

    return 0;
}