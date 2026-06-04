#include<iostream>
#include<vector>
#include<algorithm>

#define N 50001
#define LOG 18

using namespace std;

int n,k;
int dep[N],cnt[N],fa[N][LOG];
bool vis1[N],vis2[N];

vector<int> graph[N];

void dfs(int u,int father){
    fa[u][0]=father;
    dep[u]=dep[father]+1;
    vis1[u]=true;

    for(int i=1;i<LOG;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
        if(fa[u][i]==0) break;
    }

    for(int &neighbor:graph[u])
        if(!vis1[neighbor])
            dfs(neighbor,u);
}

int lca(int u,int v){
    if(dep[u]<dep[v])   swap(u,v);

    for(int i=LOG-1;i>=0;i--)
        if(dep[fa[u][i]]>=dep[v])
            u=fa[u][i];
    
    if(u==v)    return u;

    for(int i=LOG-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }

    return fa[u][0];
}

void dfs_cnt(int u){
    vis2[u]=true;

    for(auto &neighbor:graph[u])
        if(!vis2[neighbor])
        {
            dfs_cnt(neighbor);
            cnt[u]+=cnt[neighbor];
        }
}

bool cmp(int x,int y){
    return x>y;
}

int main(){
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0;i<LOG;i++)  fa[0][i]=0;

    dfs(1,0);

    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        cnt[a]++;
        cnt[b]++;
        cnt[lca(a,b)]--;
        
        cnt[fa[lca(a,b)][0]]--;
    }

    dfs_cnt(1);

    sort(cnt+1,cnt+n+1,cmp);

    printf("%d\n",cnt[1]);

    return 0;
}