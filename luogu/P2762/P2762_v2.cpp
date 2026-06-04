#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<cstring>

#define M 51
#define N 51
const long long INF=1e18;

using namespace std;

int m,n,sum;
int level[M],iter[M];
bool vis[M];

struct edge{
    int to,rev;
    long long cap;
};  

vector<edge> graph[M];

void add_edge(int a,int b,long long c){
    graph[a].push_back({b,(int)graph[b].size(),c});
    graph[b].push_back({a,(int)graph[a].size()-1,0});
}

bool bfs(int s,int t){
    queue<int> q;
    q.push(s);

    memset(level,-1,sizeof(level));
    level[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto &e:graph[x])
        {
            if(e.cap>0&&level[e.to]==-1)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
            }
        }
    }

    return level[t]!=-1;
}

long long dfs(int u,int t,long long f){
    if(u==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[u];i<graph[u].size();i++)
    {
        if(graph[u][i].cap>0&&level[graph[u][i].to]==level[u]+1)
        {
            long long flow=dfs(graph[u][i].to,t,min(f,graph[u][i].cap));
            if(flow>0)
            {
                graph[u][i].cap-=flow;
                graph[graph[u][i].to][graph[u][i].rev].cap+=flow;
                return flow;
            }
        }
    }

    return 0;
}

long long max_flow(int s,int t){
    long long maxf=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        long long flow=dfs(s,t,INF);
        while(flow>0){
            maxf+=flow;
            flow=dfs(s,t,INF);
        }
    }

    return maxf;
}

void bfs_vis(int s){
    queue<int> q;
    q.push(s);
    vis[s]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto &e:graph[x])
        {
            if(e.cap>0&&!vis[e.to])
            {
                q.push(e.to);
                vis[e.to]=true;
            }
        }
    }
}

int main(){
    cin>>m>>n;

    sum=0;

    cin.ignore();

    for(int i=1;i<=m;i++)
    {
        long long x;
        cin>>x;

        sum+=x;
        
        add_edge(0,i,x);

        string s;
        getline(cin,s);

        stringstream ss(s);

        while(ss>>x){
            add_edge(i,m+x,INF);
        }
    }

    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;

        add_edge(m+i,m+n+1,x);
    }

    long long ans=sum-max_flow(0,m+n+1);

    bfs_vis(0);

    for(int i=1;i<=m;i++)
        if(vis[i])
            cout<<i<<" ";

    cout<<endl;

    for(int i=m+1;i<=m+n;i++)
        if(vis[i])
            cout<<i-m<<" ";

    cout<<endl;

    cout<<ans<<endl;

    return 0;
}