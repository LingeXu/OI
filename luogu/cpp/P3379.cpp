#include<iostream>
#include<vector>

#define N 500001
#define LOG 18

using namespace std;

int n,m,s;
int fa[N][LOG],depth[N];
bool vis[N];

vector<int> tree[N];

void dfs(int u,int father){
    vis[u]=true;
    fa[u][0]=father;
    depth[u]=depth[father]+1;

    for(int i=1;i<LOG;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }

    for(int &neighbor:tree[u])
    {
        if(!vis[neighbor])
        dfs(neighbor,u);
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);

    for(int i=LOG-1;i>=0;i--)
    {
        if(depth[fa[u][i]]<depth[v])
        {
            u=fa[u][i];
        }
    }

    u=fa[u][0];

    if(u==v)    return u;

    else
    {
        for(int i=LOG-1;i>=0;i++)
        {
            if(fa[u][i]!=fa[v][i])
            {
                u=fa[u][i];
                v=fa[v][i];
            }
        }

        return fa[u][0];
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);

    for(int i=0;i<n-1;i++)
    {
        int from,to;
        scanf("%d%d",&from,&to);

        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    for(int i=0;i<LOG;i++)  fa[0][i]=0;
    depth[0]=0;

    dfs(s,0);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        printf("%d\n",lca(a,b));
    }

    return 0;
}