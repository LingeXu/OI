#include<iostream>
#include<vector>
#include<algorithm>

#define N 201
#define M 19900
#define Q 50001
#define INF 0x3f3f3f3f

using namespace std;

int t[N],dist[N][N];

/*struct edge{
    int from,to,weight;
}e[M];//下标表示建成时间*/

vector<pair<pair<int,int>,int> > g[N];

vector<pair<pair<int,int>,int> > graph[N];//同上，包含目前建成的边

void floyd(int u,int v,int t){
    for(auto &edge:graph[t])
    {
        dist[u][v]=min(dist[u][v],dist[u][edge.first.first]+edge.second+dist[edge.first.second][v]);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)    scanf("%d",&t[i]);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);

        /*e[max(t[u],t[v])].from=u;
        e[max(t[u],t[v])].to=v;
        e[max(t[u],t[v])].weight=w;*/

        g[max(t[u],t[v])].push_back({{u,v},w});
        g[max(t[u],t[v])].push_back({{v,u},w});
    }

    int now=0;
    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<n;i++)    dist[i][i]=0;

    int q;
    scanf("%d",&q);

    for(int i=1;i<=q;i++)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        
        for(int i=now;i<=t;i++)
        {
            for(auto &edge:g[i])
            {
                graph[i].push_back({{edge.first.first,edge.first.second},edge.second});
            }
            floyd(x,y,i);
        }

        if(dist[x][y]==INF)
            printf("-1\n");

        else    printf("%d\n",dist[x][y]);
    }

    return 0;
}