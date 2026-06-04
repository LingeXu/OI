#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 1000001
#define M 1000001
#define INF 0x3f3f3f3f

using namespace std;

vector < pair<int,int> > graph[N],rgraph[N];
int dist1[N],dist2[N];
bool vis[N];

void dijkstra(int start,vector< pair<int,int> > g[],int d[]){
    memset(vis,0,sizeof(vis));
    d[start]=0;
    priority_queue < pair<int,int>,vector < pair <int,int> > ,greater < pair <int,int> > > pq;
    pq.push({0,start});

    while(!pq.empty()){
        int u=pq.top().second;
        int v=pq.top().first;
        pq.pop();

        if(vis[u])
            continue;
        vis[u]=true;

        
        for(auto &edge:g[u])
        {
            if(d[edge.first]>d[u]+edge.second)
            {
                d[edge.first]=d[u]+edge.second;
                pq.push({d[edge.first],edge.first});
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        graph[a].push_back({b,c});
        rgraph[b].push_back({a,c});
    }

    memset(dist1,0x3f,sizeof(dist1));
    memset(dist2,0x3f,sizeof(dist2));
    
    long long sum=0;

    dijkstra(1,graph,dist1);

    dijkstra(1,rgraph,dist2);

    for(int i=2;i<=n;i++)
    {
        sum+=(dist1[i]+dist2[i]);
    }

  /*  for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",dist1[i],dist2[i]);
    }*/

    printf("%lld",sum);
    return 0;
}