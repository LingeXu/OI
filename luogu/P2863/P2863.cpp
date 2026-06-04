#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<cstring>

#define N 10001
#define M 50001

using namespace std;

vector<int> graph[N];

int dfn[N];
int low[N];
int cnt;
bool vis[N];
int ans;
int sz;

stack<int> node2vis;

void tarjan(int start){
    dfn[start]=low[start]=++cnt;
    node2vis.push(start);
    vis[start]=true;
    sz=0;

    for(int &node:graph[start])
    {
        if(!dfn[node])
        {
            tarjan(node);   
            low[start]=min(low[start],low[node]);
        }

        else if(vis[node])
        {
            low[start]=min(low[start],dfn[node]);
        }
    }

    if(low[start]==dfn[start])
    {
        while(1){
            int x=node2vis.top();
            node2vis.pop();
            vis[x]=false;
            sz++;
            if(x==start)    break;
        }
    }

    if(sz>1)    
    ans++;

    sz=0;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);

        graph[u].push_back(v);
    }

    cnt=0;
    ans=0;
    memset(vis,0,sizeof(vis));

    for(int i=1;i<=n;i++)   if(!dfn[i]) tarjan(i);
    printf("%d\n",ans);

    return 0;
}