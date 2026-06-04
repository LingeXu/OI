#include<iostream>
#include<algorithm>

#define N 10001
#define M 20001

using namespace std;

int n,m,s,t;

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)  fa[rx]=ry;
}

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int kruskal(int s,int t){
    for(int i=0;i<m;i++)
    {
        int from=e[i].u,to=e[i].v;
        unite(from,to);
        if(find(s)==find(t))    return e[i].w;
    }

    return -1;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;
    }

    sort(e,e+m,cmp);

    for(int i=1;i<n;i++)    fa[i]=i;

    printf("%d\n",kruskal(s,t));

    return 0;
}