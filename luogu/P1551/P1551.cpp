#include<iostream>

#define N 5001
#define M 5001
#define P 5001

using namespace std;

struct edge{
    int u,v;
}e[M],inq[P];

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        e[i].u=a;
        e[i].v=b;
    }

    for(int i=0;i<n;i++)    fa[i]=i;

    for(int i=0;i<m;i++)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            fa[find(e[i].v)]=find(e[i].u);
        }
    }

    for(int i=0;i<p;i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);

        if(find(c)==find(d))    printf("Yes\n");
        else    printf("No\n");
    }

    return 0;
}