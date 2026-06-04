#include<iostream>
#include<cstring>

#define N 2001
#define M 5001
#define INF 0x3f3f3f3f

using namespace std;

int dist[N];

struct edge{
    int u,v,w;
}e[2*M];

bool bellmanford(int cnt){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;

    for(int i=1;i<cnt;i++)
    {
        bool update=false;

        for(int j=1;j<=cnt;j++)
        {
            if(dist[e[j].u]!=INF&&dist[e[j].v]>dist[e[j].u]+e[j].w)
            {
                dist[e[j].v]=dist[e[j].u]+e[j].w;
                update=true;
            }
        }

        if(!update) return false;
    }

    for(int j=1;j<=cnt;j++)
        if(dist[e[j].u]!=INF&&dist[e[j].v]>dist[e[j].u]+e[j].w)
            return true;

    return false;
}

int main(){
    int t;
    scanf("%d",&t);

    while(t>0){
        int n,m;
        scanf("%d%d",&n,&m);

        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);

            e[++cnt].u=a;
            e[cnt].v=b;
            e[cnt].w=c;

            if(c>=0)
            {
                e[++cnt].u=b;
                e[cnt].v=a;
                e[cnt].w=c;
            }
        }

        if(bellmanford(cnt))    printf("YES\n");
        else    printf("NO\n");
        
        t--;
    }

    return 0;
}