#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 1001
#define M 100001
#define INF 0x3f3f3f3f

using namespace std;

vector < pair<int,int> > graph[N];
int dist[N];
bool vis[N];

void dijkstra(int start){
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;
    priority_queue < pair<int,int>,vector < pair <int,int> > ,greater < pair <int,int> > > pq;
    pq.push({0,start});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto &edge:graph[u])
        {
            if(dist[edge.first]>dist[u]+edge.second)
            {
                dist[edge.first]=dist[u]+edge.second;
                pq.push({dist[edge.first],edge.first});
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
    }

    int sum=0;

    dijkstra(1);

    for(int i=2;i<=n;i++)
    {
        sum+=dist[i];
    }

    for(int i=2;i<=n;i++)
    {
        dijkstra(i);
        sum+=dist[1];
    }

    printf("%d",sum);
    return 0;
}