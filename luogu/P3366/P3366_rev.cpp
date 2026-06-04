#include<iostream>
#include<algorithm>

#define N 5001
#define M 200001

using namespace std;

int n,m,ans,cnt;
int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)
    fa[rx]=ry;
}

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

void kruskal(){
    for(int i=0;i<m;i++)
    {
        if(find(e[i].u)==find(e[i].v))  continue;

        else
        {
            unite(e[i].u,e[i].v);
            ans+=e[i].w;
            cnt--;
        }
    }
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

    ans=0;
    cnt=n;

    sort(e,e+m,cmp);

    for(int i=1;i<=n;i++)   fa[i]=i;

    kruskal();

    if(cnt==1)  printf("%d\n",ans);
    else    printf("orz\n");
    
    return 0;
}