#include<iostream>
#include<vector>
#include<cmath>

#define N 50001
#define K 100001
#define LOG 18

using namespace std;

int f[N][LOG];
int dep[N];
int cnt[N];

struct edge{
    int u,v;
}e[N];

vector<int> graph[N];

void dfs(int start,int father){
    f[start][0]=father;
    dep[start]=dep[father]+1;

    for(int i=1;i<LOG;i++)  f[start][i]=f[f[start][i-1]][i-1];

    for(auto &point:graph[start])
    {
        if(point==father)   continue;
        dfs(point,start);
    }
}

void lca(int u,int v){

    if(dep[u]<dep[v])   swap(u,v);
    for(int i=LOG-1;i>=0;i--)
    {
        if(dep[f[u][i]]<=dep[v])
        {
            for(int j=0;j<=i;j++)   cnt[f[u][j]]++;
            u=f[u][i];
        }

        if(u==v)    cnt[u]--;

        for(int i=LOG-1;i>=0;i--)
        {
            if(f[u][i]!=f[v][i])
            {
                for(int j=0;j<=i;j++)  
                {
                    cnt[f[u][j]]++;
                    cnt[f[v][j]]++;
                } 
                u=f[u][i];
                v=f[v][i];
            }
        }
        cnt[f[u][0]]++;
    }
}

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        e[i].u=a;
        e[i].v=b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dep[0]=0;
    memset(cnt,0,sizeof(cnt));

    dfs(1,0);

    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        lca(a,b);
    }

    sort(cnt,cnt+n,cmp);

    printf("%d\n",cnt[0]);

    return 0;
}