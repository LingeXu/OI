#include<iostream>
#include<vector>
#include<stack>
#include<queue>

#define N 20001

using namespace std;

int low[N],dfn[N];
int cnt,ans;
bool in_stack[N],vis1[N],vis2[N],inq1[N],inq2[N];

stack<int> node2vis;

vector<int> graph[N];

void tarjan(int u){
    low[u]=dfn[u]=++cnt;
    node2vis.push(u);
    in_stack[u]=true;

    for(int &to:graph[u])
    {
        if(!dfn[to])
        {
            tarjan(to);
            low[u]=min(low[u],low[to]);
        }

        else if(in_stack[to])
        {
            low[u]=min(low[u],dfn[to]);
        }
    }

    if(low[u]==dfn[u])
    {
        while(1){
            int x=node2vis.top();
            node2vis.pop();
            in_stack[x]=false;
            if(x==u)    break;
        }
    }
}

/*void dfs(int u){
    vis2[u]=true;

    for(int &to:graph[u])
    {
        if(!vis2[to])
        {
            if(low[to]>=dfn[u]&&u!=1)
                printf("%d\n",u);

            dfs(to);
        }
    }
}*/


void bfs_cnt(int u){
    queue<int> q;
    q.push(u);
    inq1[u]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis1[x]=true;
        inq1[x]=false;

        for(int &to:graph[x])
            if(low[to]>=dfn[u]&&u!=1)
            {
                ans++;
                q.push(to);
                inq1[to]=true;
            }     
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    inq2[u]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis2[x]=true;
        inq2[x]=false;

        for(int &to:graph[x])
            if(low[to]>=dfn[u]&&u!=1)
            {
                printf("%d ",u);
                q.push(to);
                inq2[to]=true;
            }
    }
}

/*void dfs_cnt(int u){
    vis1[u]=true;

    for(int &to:graph[u])
    {
        if(!vis1[to])
        {
            if(low[to]>=dfn[u]&&u!=1)
                ans++;

            dfs_cnt(to);
        }
    }
}*/

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cnt=0;
    ans=0;

    tarjan(1);

    if(graph[1].size()==0)
    {
        printf("1\n");
        ans++;
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i]) 
            tarjan(i);

    /*for(int i=1;i<=n;i++)
        if(!vis1[i])
            dfs_cnt(i);

    printf("%d\n",ans);

    for(int i=1;i<=n;i++)
        if(!vis2[i])
            dfs(i);*/

    for(int i=1;i<=n;i++)
    {
        if(!vis1[i])
            bfs_cnt(i);
    }

    cout<<ans<<endl;

    for(int i=1;i<=n;i++)
    {
        if(!vis2[i])
            bfs(i);
    }


    return 0;
}