#include<iostream>
#include<algorithm>

#define N 1001
#define M 10001
#define K 11

using namespace std;

int n,m,k;

int ans,t,cnt;

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){

    return x.w<y.w;
}

void kruskal(){
    if(k==n) 
    {
        printf("0\n");
        return;
    }
    
    if(k>n) 
    {
        printf("No Answer\n");
        return;
    }
    
    while(t<n-k){
        bool update=false;

        for(int i=cnt;i<m;i++)
        {
            int rx=find(e[i].u),ry=find(e[i].v);
            if(rx!=ry)
            {
                fa[rx]=ry;
                ans+=e[i].w;
                update=true;
                t++;
                cnt=i;
                break;
            }
        }

        if(!update) 
        {
            printf("No Answer\n");
            return;
        }
    }

    printf("%d\n",ans);
    return;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;

    }

    sort(e,e+m,cmp);

    ans=0;
    t=0;
    cnt=0;

    for(int i=1;i<=n;i++)   fa[i]=i;

    kruskal();

    return 0;
}