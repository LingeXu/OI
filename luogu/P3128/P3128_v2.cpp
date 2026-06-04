#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define N 50001
#define K 100001
#define LOG 18

using namespace std;

vector<int> graph[N];
int cnt[N];

bool cmp(int x,int y){
    return x>y;
}

int f[N][LOG];
int dep[N];

void dfs(int start,int father){
    f[start][0]=father;
    dep[start]=dep[father]+1;

    for(int i=1;i<LOG;i++)   f[start][i]=f[f[start][i-1]][i-1];

    for(auto &node:graph[start])
    {
        if(node==father)    continue;

        dfs(node,start);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])   swap(u,v);

    for(int i=LOG-1;i>=0;i--)
    {
        if(dep[f[u][i]]>=dep[v])    u=f[u][i];
    }

    if(u==v)    return u;

    for(int i=LOG-1;i>=0;i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }

    return f[u][0];
}

int ans=0;
void dfs_cnt(int start,int father){
    for(auto &node:graph[start])
    {
        if(node==father)    continue;

        dfs_cnt(node,start);
        cnt[start]+=cnt[node];
    }
    ans=max(ans,cnt[start]);
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dep[0]=0;
    dfs(1,0);

    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        cnt[a]++;
        cnt[b]++;
        cnt[lca(a,b)]--;
        if(f[lca(a,b)][0])  cnt[f[lca(a,b)][0]]--;  

    }

    dfs_cnt(1,0);

    printf("%d\n",ans);
    return 0;
}