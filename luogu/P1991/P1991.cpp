#include<iostream>
#include<cmath>
#include<cstring>

#define S 501
#define P 501

using namespace std;

struct point{
    int x,y;
}c[P];

struct edge{
    int u,v;
    double w;
}e[P*P/2],u[P*P/2];

bool cmp(edge n,edge m){
    return n.w<m.w;
}

int fa[P];

int find(int x){
    return fa[x]==x?x:find(fa[x]);
}

int main(){
    int s,p;
    scanf("%d%d",&s,&p);

    for(int i=1;i<=p;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        
        c[i]={x,y};
    }

    int k=0;

    for(int i=1;i<p;i++)
    {
        for(int j=i+1;j<=p;j++)
        {
            e[k]={i,j,sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y))};
            k++;
        }
    }

    sort(e,e+p*(p-1)/2,cmp);

    for(int i=1;i<=p;i++)   fa[i]=i;

    int cnt=0;
    int i=0;

    while(cnt<p*(p-1)/2){
        if(find(e[cnt].u)!=find(e[cnt].v))
        {
            fa[find(e[cnt].v)]=find(e[cnt].u);
            u[i]=e[cnt];
            i++;
        }

        cnt++;
    }

    printf("%.2f\n",u[i-s].w);

    return 0;
}