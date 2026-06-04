#include<iostream>
#include<algorithm>
#include<cstring>

#define N 201
#define INF 0x3f3f3f3f

using namespace std;

int n,m,q;
int t[N],dist[N][N];

int main(){
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);

    memset(dist,0x3f,sizeof(dist));

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        dist[a][b]=c;
        dist[b][a]=c;
    }

    for(int i=0;i<n;i++)    dist[i][i]=0;

    int now=0;

    scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        while(now<n&&t[now]<=c){
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    dist[j][k]=min(dist[j][k],dist[j][now]+dist[now][k]);

            now++;
        }

        if(dist[a][b]!=INF&&t[a]<=c&&t[b]<=c)  printf("%d\n",dist[a][b]);
        else    printf("-1\n");
    }

    return 0;
}