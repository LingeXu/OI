#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>

#define N 2001
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[N];

int dist[N];
bool vis[N];
int sum[N];

void dijkstra(int start){
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;
    memset(vis,0,sizeof(vis));
    memset(sum,0,sizeof(sum));
    sum[start]=1;

    priority_queue <pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    pq.push({0,start});

    while(!pq.empty()){
        int u=pq.top().first;
        int v=pq.top().second;

        pq.pop();

        if(vis[v])  continue;

        vis[v]=true;

        for(auto &edge:graph[v])
        {
            if(dist[edge.first]>dist[v]+edge.second)
            {
                dist[edge.first]=dist[v]+edge.second;
                pq.push({dist[edge.first],edge.first});
                sum[edge.first]=sum[v];
            }
            else if(dist[edge.first]==dist[v]+edge.second)
            {
                sum[edge.first]+=sum[v];
            }
        }
    }
}

int main(){
    int n,e;
    scanf("%d%d",&n,&e);

    for(int i=1;i<=e;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        bool ans=true;
        for(auto &element:graph[a])
        {
            if(element.first==b&element.second==c)
            {
                ans=false;
            }
        }

        if(ans)
            graph[a].push_back({b,c});
    }

    dijkstra(1);

    if(dist[n]!=INF)
        printf("%d ",dist[n]);
    else
        printf("No answer\n");

    if(sum[n]!=0)
        printf("%d",sum[n]);

    return 0;
}