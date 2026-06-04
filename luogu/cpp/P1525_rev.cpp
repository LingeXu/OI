#include<iostream>
#include<algorithm>

#define N 20001
#define M 100001

using namespace std;

int n,m;
int fa[N],enemy[N];

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){
    return x.w>y.w;
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)  fa[rx]=ry;
}

int main(){
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;
    }

    sort(e,e+m,cmp);

    for(int i=1;i<=n;i++)    fa[i]=i;
    
    for(int i=0;i<m;i++)
    {
        int one=e[i].u,two=e[i].v;

        if(find(one)==find(two))  
        {
            printf("%d\n",e[i].w);
            return 0;
        }

        if(!enemy[one])  enemy[one]=two;
        else    unite(enemy[one],two);

        if(!enemy[two])  enemy[two]=one;
        else    unite(enemy[two],one);
    }

    printf("0\n");
    return 0;
}