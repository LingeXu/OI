#include<iostream>

#define N 201
#define M 19901
#define Q 50001
#define INF 0x3f3f3f3f

using namespace std;

int t[N],dist[N][N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)    scanf("%d",&t[i]);

    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<n;i++)    dist[i][i]=0;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);

        dist[u][v]=dist[v][u]=w;
    }

    int q;
    scanf("%d",&q);

    int now=0;

    for(int i=0;i<q;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        while(now<n&&t[now]<=c){
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][now]+dist[now][j]);
                }
            }
            now++;
        }

        if(dist[a][b]!=INF&&t[a]<=c&&t[b]<=c)
            printf("%d\n",dist[a][b]);

        else    printf("-1\n");

        
    }

    return 0;
}