#include<iostream>
#include<vector>
#include<cstring>

#define N 300001
#define LOG 18

using namespace std;

vector<int> graph[N];

int dep[N];
int f[N][LOG];
int cnt[N];

void dfs(int start,int father){
    f[start][0]=father;
    dep[start]=dep[father]+1;

    for(int i=1;i<LOG;i++)  f[start][i]=f[f[start][i-1]][i-1];

    for(int node:graph[start])
    {
        if(node==father)    continue;

        dfs(node,start);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])   swap(u,v);

    for(int i=LOG-1;i>=0;i--)
    {
        if(dep[f[u][i]]>=dep[v])
        {
            u=f[u][i];
        }
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

void dfs_cnt(int start,int father){
    for(int node:graph[start])
    {
        if(node==father)    continue;

        dfs_cnt(node,start);

        cnt[start]+=cnt[node];
    }
    
}

int main(){
    int n;
    scanf("%d",&n);

    int v[N];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }

    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dep[0]=0;
    memset(cnt,0,sizeof(cnt));

    dfs(1,0);

    for(int i=1;i<n;i++)
    {
        cnt[v[i]]++;
        cnt[v[i+1]]++;

        cnt[lca(v[i],v[i+1])]--;

        if(f[lca(v[i],v[i+1])][0])
            cnt[f[lca(v[i],v[i+1])][0]]--;
    }

    dfs_cnt(1,0);

    for(int i=2;i<=n;i++)   cnt[i]--;

    for(int i=1;i<=n;i++)   printf("%d\n",cnt[i]);

    return 0;
}