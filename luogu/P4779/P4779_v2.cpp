#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 100001
#define INF 0x3f3f3f3f

using namespace std;

int n,m,s;
vector<pair<int,int> > graph[N];
int dist[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
bool visit[N];

void dijkstra(int start){
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;

    pq.push({0,start});

    while(!pq.empty()){

        int u=pq.top().second;
        pq.pop();

        if(visit[u])
            continue;
        visit[u]=true;

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
    scanf("%d%d%d",&n,&m,&s);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        graph[a].push_back({b,c});
    }

    dijkstra(s);

    for(int i=1;i<=n;i++)
        printf("%d ",dist[i]);

    return 0;
}