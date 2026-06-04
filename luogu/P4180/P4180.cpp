#include<iostream>
#include<vector>
#include<cmath>

#define N 100001
#define M 300001
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge p,edge q){
    return p.w<q.w;
}

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

vector<pair<int,int> >graph[N];

bool vis[N];

int max_edge;
void dfs(int start){
    vis[start]=true;

    for(auto& edge:graph[start])
    {
        if(!vis[edge.first])  
        {
            max_edge=max(max_edge,edge.second);
            dfs(vis[edge.first]);
        }  
    }
}

int dep[N];
int f[N][18];

void dfs(int start,int father,int end){
    dep[start]=dep[father]+1;

    f[start][0]=father;

    for(int i=18;i>=0;i--)
    {
        if(dep[f[start][i]]<dep[end])
        {
            
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;

        graph[a].push_back({b,c});
    }

    for(int i=1;i<=n;i++)   fa[i]=i;

    sort(e,e+m,cmp);

    int sum=0,cnt1=0,cnt2=0;

    while(cnt2<m){
        if(find(e[cnt1].u)!=find(e[cnt1].v))
        {
            fa[find(e[cnt1].u)]=find(e[cnt1].v);
            sum+=e[cnt1].w;
            cnt1++;
        }
        cnt2++;
    }

    memset(vis,0,sizeof(vis));

    int sup=INF;
    for(int i=cnt1;i<m;i++)
    {

    }

    printf("%d\n",sum);

    return 0;
}