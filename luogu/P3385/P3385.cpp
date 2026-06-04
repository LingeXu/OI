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

bool bellmanford(int start,int n){
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;

    int sum=0;
    while(sum<=n-1){
        bool update=false;

        for(int i=1;i<=n;i++)
        {
            for(auto &edge:graph[i])
            {
                if(dist[edge.first]>dist[i]+edge.second)
                {
                    dist[edge.first]=dist[i]+edge.second;
                    update=true;
                }
            }
        }

        if(!update)
            return 0;

        sum++;
    }

    for(int i=1;i<=n;i++)
    {
        for(auto &edge:graph[i])
        {
            if(dist[edge.first]<INF&&dist[edge.first]>dist[i]+edge.second)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    int t;
    scanf("%d",&t);

    int sum=0;
    while(sum<t){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);

            graph[u].push_back({v,w});

            if(w>=0)    graph[v].push_back({u,w});
        }

        if(bellmanford(1,n))    printf("YES\n");
        else    printf("NO\n");


        for(int i=1;i<=n;i++)
        {

            graph[i].clear();
        }

        sum++;
    }

    return 0;
}