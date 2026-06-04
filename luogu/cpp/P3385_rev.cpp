#include<iostream>
#include<queue>
#include<cstring>

#define N 2001
#define M 3001
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[N];

struct edge{
    int u,v,w;
}e[2*M];

int main(){
    int t;
    scanf("%d",&t);

    while(t>0){
        int n,m;
        scanf("%d%d",&n,&m);

        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);

            //graph[a].push_back({c,b});

            e[i].u=a;
            e[i].v=b;
            e[i].w=c;

            if(c>=0)
            {
                e[++i].u=b;
                e[++i].v=a;
                e[++i].w=c;
                m++;
            }
        }

        int dist[N];
        memset(dist,0x3f,sizeof(dist));
        dist[1]=0;

        int cnt=0;
        while(cnt<n-1){
            bool update1=false;
            for(int i=1;i<=m;i++)
            {
                if(dist[e[i].u]!=INF&&dist[e[i].v]>dist[e[i].u]+e[i].w)
                {
                    dist[e[i].v]=dist[e[i].u]+e[i].w;
                    update1=true;
                }
            }

            if(!update1)    break;

            cnt++;
        }

        bool update2=false;
        for(int i=1;i<=m;i++)
            if(dist[e[i].u]!=INF&&dist[e[i].v]>dist[e[i].u]+e[i].w)
                update2=true;

        if(update2) printf("YES\n");
        else    printf("NO\n");

        t--;
    }

    return 0;
}