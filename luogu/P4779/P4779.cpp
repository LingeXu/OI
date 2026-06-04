#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

#define N 100001
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> >graph[N];

int dist[N];


int n,m,s;

bool visited[N];

void dijkstra(int start){
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;

    for(int i=1;i<n;i++)
    {
        int u=-1,min_dist=INF;

        for(int j=1;j<=n;j++)
        {
            if(!visited[j]&&dist[j]<=min_dist)
            {
                min_dist=dist[j];
                u=j;
            }
        }

        if(u==-1)   break;
        visited[u]=true;

        for(auto &edge:graph[u])
        {
            dist[edge.first]=min(dist[edge.first],dist[u]+edge.second);
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
    {
        printf("%d ",dist[i]);
    }

    return 0;
}