#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 1000001
#define M 2000001
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[N];
int dist[N];
int dist_count[N];

void dijkstra(int start){

    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,start});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto &edge:graph[u])
        {
            if(dist[edge.second]>dist[u]+edge.first)
            {
                dist[edge.second]=dist[u]+edge.first;
                pq.push({dist[edge.second],edge.second});
                dist_count[edge.second]=dist_count[u];
            }
            else if(dist[edge.second]==dist[u]+edge.first)
            {
                dist_count[edge.second]=(dist_count[edge.second]+dist_count[u])%100003;
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        graph[a].push_back({1,b});
        graph[b].push_back({1, a});
    }

    dist_count[1]=1;
    for(int i=2;i<=n;i++)  
        dist_count[i]=0;

    dijkstra(1);

    for(int i=1;i<=n;i++)
        printf("%d\n",dist_count[i]%100003);

    return 0;
}