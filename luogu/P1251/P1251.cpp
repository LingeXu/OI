#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 2001
#define INF 0x3f3f3f3f

using namespace std;

int n,p,m,f,k,s;

int dist[2*N+2],prevv[2*N+2],preve[2*N+2];
bool inq[2*N+2];

struct edge{
    int to,rev,cap,cost;
};

vector<edge> graph[2*N+2];

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

long long min_cost_max_flow(int s,int t){
    long long flow=0,cost=0;

    while(spfa(s,t)){
        long long f=INF;
        for(int i=t;i!=s;i=prevv[i])
        {
            edge &e=graph[prevv[i]][preve[i]];
            f=min((int)f,e.cap);
        }

        flow+=f;
        cost+=f*dist[t];

        for(int i=t;i!=s;i=prevv[i])
        {
            edge &e=graph[prevv[i]][preve[i]];
            e.cap-=f;
            graph[e.to][e.rev].cap+=f;
        }
    }

    return cost;
}

int main(){
    cin>>n;

    for(int i=1;i<=n;i++)   
    {
        int x;
        cin>>x;
    
        add_edge(0,i,x,0);
        add_edge(i+n,2*n+1,x,0);
    }

    cin>>p>>m>>f>>k>>s;

    for(int i=n+1;i<=2*n;i++)
        add_edge(0,i,INF,p);

    for(int i=1;i<n;i++)
        add_edge(i,i+1,INF,0);

    for(int i=1;i<=n-m;i++)
        add_edge(i,i+n+m,INF,f);

    for(int i=1;i<=n-k;i++)
        add_edge(i,i+n+k,INF,s);

    /*for(int i=0;i<=2*n+2;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" "<<graph[i][j].to<<endl;
        }
    }*/

    cout<<min_cost_max_flow(0,2*n+1)<<endl;

    return 0;
}