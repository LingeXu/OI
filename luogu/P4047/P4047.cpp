#include<iostream>
#include<cmath>
#include<algorithm>

#define N 1001

using namespace std;

struct point{
    int x,y;
}p[N];

struct edge{
    int u,v;
    double w;
}e[N*N/2];

bool cmp(edge p,edge q){
    return p.w<q.w;
}

int fa[N];

int find(int pq){
    return fa[pq]==pq?pq:find(fa[pq]);
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        p[i].x=a;
        p[i].y=b;
    }

    int index=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            
            e[index].w=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
            e[index].u=i;
            e[index].v=j;
            index++;
        }
    }

    sort(e,e+n*(n-1)/2,cmp);

    for(int i=1;i<=n;i++)   fa[i]=i;

    int cnt=0,ans1=0;
    while(cnt<n*(n-1)/2&&ans1<n-k){
        if(find(e[cnt].u)!=find(e[cnt].v))
        {
            fa[find(e[cnt].u)]=find(e[cnt].v);
            ans1++;
        }

        cnt++;
    }

    while(find(e[cnt].u)==find(e[cnt].v))   cnt++;

    printf("%.2f\n",e[cnt].w);
    
    return 0;
}