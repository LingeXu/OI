#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

#define N 10001
#define INF 0x3f3f3f

using namespace std;

vector< pair < int,int > > graph[N];

bool visited[N];

int n,m,s;
int dist[N];

void dijkstra(int start){
    memset(dist,INF,sizeof(dist));
    dist[start]=0;

    for(int i=1;i<=n;i++)
    {
        int u=-1,min_dist=INF;

        for(int j=1;j<=n;j++)
        {
            if(!visited[j]&&dist[j]<min_dist)
            {
                min_dist=dist[j];
                u=j;
            }
        }

        if(u==-1) break;
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
        if(dist[i]==INF)
            cout<<(1u << 31) - 1<<" ";
        else
            printf("%d ",dist[i]);
    }
    
    return 0;
}