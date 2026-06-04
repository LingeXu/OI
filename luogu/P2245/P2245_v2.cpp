#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>

#define N 100001
#define M 300001
#define LOG 18

using namespace std;

struct edge{
    int u,v,w;
}e[M];

vector<pair<int,int> >graph[N];

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool cmp(edge p,edge q){
    return p.w<q.w;
}

int n,m;
int f[N][LOG];
int maxw[N][LOG];
int dep[N];

void dfs(int start,int father){
    f[start][0]=father;
    dep[start]=dep[father]+1;

    for(int k=1;k<LOG;k++)
    {
        f[start][k]=f[f[start][k-1]][k-1];
        maxw[start][k]=max(maxw[start][k-1],maxw[f[start][k-1]][k-1]);
    }

    for(auto &edge:graph[start])
    {
        if(edge.second==father) continue;
        maxw[edge.second][0]=edge.first;
        dfs(edge.second,start);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])   swap(u,v);

    int res=0;

    for(int i=LOG-1;i>=0;i--)
    {
        if(dep[f[u][i]]>=dep[v])
        {
            res=max(res,maxw[u][i]);
            u=f[u][i];
        }
    }

    if(u==v)    return res;

    for(int i=LOG-1;i>=0;i--)
    {
        if(f[u][i]!=f[v][i])
        {
            res=max(res,maxw[u][i]);
            res=max(res,maxw[v][i]);
            u=f[u][i];
            v=f[v][i];
        }
    }
    res=max(res,maxw[u][0]);
    res=max(res,maxw[v][0]);

    return res;
}

void kruskal(){
    sort(e,e+m,cmp);

    for(int i=1;i<=n;i++)   fa[i]=i;

    for(int i=0;i<m;i++)
    {
        int ra=find(e[i].u),rb=find(e[i].v);
        if(ra!=rb)
        {
            graph[e[i].u].push_back({e[i].w,e[i].v});
            graph[e[i].v].push_back({e[i].w,e[i].u});

            fa[ra]=rb;

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

    for(int i=0;i<=n;i++)   dep[i]=0;
    kruskal();
    memset(maxw,0,sizeof(maxw));
    for (int i = 1; i <= n; i++) if (!dep[i]) dfs(i, 0);


    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        if(find(x)!=find(y))    printf("impossible\n");
        else    printf("%d\n",lca(x,y));
    }

    return 0;
}