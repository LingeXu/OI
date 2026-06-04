#include<iostream>

#define N 5001

using namespace std;

int n,m,p;
int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)  fa[rx]=ry;
}

struct edge{
    int u,v;
}e[N];

int main(){
    scanf("%d%d%d",&n,&m,&p);

    for(int i=1;i<=n;i++)   fa[i]=i;

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        e[i].u=a;
        e[i].v=b;

        unite(a,b);
    }

    for(int i=0;i<p;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        if(find(a)==find(b))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}