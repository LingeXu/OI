#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 1001
#define M 1001
#define INF 0x3f3f3f3f

using namespace std;

int n,m,sum;
int level[N+2*M+2],iter[N+2*M+2];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[N+2*M+2];

void add_edge(int a,int b,int c){
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
                q.push(e.to);
                level[e.to]=level[x]+1;
            }
        }
    }

    return level[t]!=-1;
}

int dfs(int u,int t,int f){
    if(u==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[u];i<graph[u].size();i++)
    {
        edge &e=graph[u][i];
        if(e.cap>0&&level[e.to]==level[u]+1)
        {
            int flow=dfs(e.to,t,min(f,e.cap));
            if(flow>0)
            {
                e.cap-=flow;
                graph[e.to][e.rev].cap+=flow;
                return flow;
            }
        }
    }

    return 0;
}

int max_flow(int s,int t){
    int maxf=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        int flow=dfs(s,t,INF);
        while(flow>0){
            maxf+=flow;
            flow=dfs(s,t,INF);
        }
    }

    return maxf;
}

int main(){
    cin>>n;

    sum=0;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        sum+=x;

        add_edge(0,i,x);
    }

    for(int i=1;i<=n;i++)
    {
        int y;
        cin>>y;

        sum+=y;

        add_edge(i,n+1,y);
    }

    cin>>m;

    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;

        int c1,c2;
        cin>>c1>>c2;

        sum+=(c1+c2);

        add_edge(0,n+i+1,c1);
        add_edge(n+m+i+1,n+1,c2);

        for(int j=1;j<=k;j++)
        {
            int a;
            cin>>a;

            add_edge(n+i+1,a,INF);
            add_edge(a,n+m+i+1,INF);
        }
    }

    //cout<<sum<<endl;

    /*for(int i=0;i<=n+2*m+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" "<<graph[i][j].to<<" "<<graph[i][j].rev<<" "<<graph[i][j].cap<<endl;
        }
    }*/

    cout<<sum-max_flow(0,n+1)<<endl;

    return 0;
}