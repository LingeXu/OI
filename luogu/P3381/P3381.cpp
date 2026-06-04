#include<iostream>
#include<vector>
#include<queue>

#define N 5001
#define M 50001
const long long INF=2e18;

using namespace std;

int n,m,s,t;

struct edge{
    int to,rev;
    long long cap,val;
};

vector<edge> graph[N];

void add_edge(int a,int b,long long c,long long d){
    graph[a].push_back({b,(int)graph[b].size(),c,d});
    graph[b].push_back({a,(int)graph[a].size()-1,0,-d});
}

bool in_queue[N];
long long dist[N];
int h[N];
int prevv[N],preve[N];

bool spfa(int s,int t){
    queue<int> q;
    q.push(s);
    memset(in_queue,0,sizeof(in_queue));
    in_queue[s]=true;
    fill(dist, dist + N, INF);
    dist[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        in_queue[x]=false;

        for(int i=0;i<graph[x].size();i++)
        {
            edge &e=graph[x][i];
            if(e.cap>0&&dist[e.to]>dist[x]+e.val+h[x]-h[e.to])
            {
                dist[e.to]=dist[x]+e.val+h[x]-h[e.to];
                prevv[e.to]=x;
                preve[e.to]=i;
                if(!in_queue[e.to])
                {
                    q.push(e.to);
                    in_queue[e.to]=true;
                }
            }
        }
    }

    return dist[t]<INF;
}

void min_cost_flow(int s,int t){
    long long flow=0,cost=0;
    memset(h,0,sizeof(h));

    while(spfa(s,t)){
        for(int i=1;i<=n;i++)   h[i]+=dist[i];
        long long d=INF;

        for(int u=t;u!=s;u=prevv[u])
        {
            d=min(d,graph[prevv[u]][preve[u]].cap);
        }
        flow+=d;
        cost+=d*h[t];

        for(int u=t;u!=s;u=prevv[u])
        {
            graph[prevv[u]][preve[u]].cap-=d;
            graph[u][graph[prevv[u]][preve[u]].rev].cap+=d;
        }
    }

    printf("%lld %lld\n",flow,cost);
}



int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=1;i<=m;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);

        add_edge(a,b,c,d);
    }

    min_cost_flow(s,t);

    return 0;
}