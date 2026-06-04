#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 10001
#define M 500001
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[N];

int dist[N];

void dijkstra(int u){
    dist[u]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({dist[u],u});

    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();

        for(auto &edge:graph[x])
        {
            if(dist[edge.second]>dist[x]+edge.first)
            {
                dist[edge.second]=dist[x]+edge.first;
                pq.push({dist[edge.second],edge.second});
            }
        }
    }

}

int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);

        graph[u].push_back({w,v});
    }

    memset(dist,0x3f,sizeof(dist));
    dijkstra(s);

    for(int i=1;i<=n;i++)
    {
        if(dist[i]!=INF)    printf("%d ",dist[i]);
        else    cout<<(1u << 31) - 1<<" ";
    }

    return 0;
}