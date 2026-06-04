#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 5001
#define INF 0x3f3f3f3f

using namespace std;

int n,m,s,t;
int dist[N],preve[N],prevv[N];
bool inq[N];

struct edge{
    int to,rev;
    long long cap,cost;
};

vector<edge> graph[N];

void add_edge(int a,int b,long long c,long long d){
    graph[a].push_back({b,(int)graph[b].size(),c,d});
    graph[b].push_back({a,(int)graph[a].size()-1,0,-d});
}

bool spfa(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;

        for(int i=0;i<graph[x].size();i++)
        {
            edge &e=graph[x][i];
            if(e.cap>0&&dist[x]+e.cost<dist[e.to]){
                dist[e.to]=dist[x]+e.cost;
                q.push(e.to);
                inq[e.to]=true;
                preve[e.to]=x;
                prevv[e.to]=i;
            }
        }
    }

    return dist[t]!=INF;
}

void min_cost_flow(int s,int t){
    long long flow=0;
    long long cost=0;

    while(spfa(s,t)){

        long long d=INF;
        for(int now=t;now!=s;now=preve[now])
        {
            d=min(d,graph[preve[now]][prevv[now]].cap);
        }

        flow+=d;
        cost+=d*dist[t];

        for(int now=t;now!=s;now=preve[now])
        {
            edge &e=graph[preve[now]][prevv[now]];
            e.cap-=d;
            graph[now][e.rev].cap+=d;
        }
    }

    printf("%lld %lld\n",flow,cost);
}

int main(){
    cin>>n>>m>>s>>t;

    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        add_edge(a,b,c,d);
    }

    min_cost_flow(s,t);

    return 0;
}