#include<iostream>
#include<cstring>
#include<algorithm>

#define N 50001
#define M 100001

using namespace std;

struct edge{
    int u,v,w;
}e[M];

int fa[N],enemy[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)  fa[rx]=ry;
}

bool cmp(edge x,edge y){
    return x.w>y.w;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)   fa[i]=i;

    memset(enemy,0,sizeof(enemy));

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;
    }

    sort(e,e+m,cmp);


    for(int i=0;i<m;i++)
    {
        int x=e[i].u,y=e[i].v;

        if(find(x)==find(y))    
        {
            printf("%d\n",e[i].w);
            break;
        }

        if(!enemy[x])   enemy[x]=y;
        else    unite(enemy[x],y);

        if(!enemy[y])   enemy[y]=x;
        else    unite(x,enemy[y]);
    }

    return 0;
}