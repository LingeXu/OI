#include<iostream>
#include<vector>
#include<queue>

#define N 51
#define M 51
#define INF 0x3f3f3f3f

using namespace std;

int m,n,now1,now2,sum;
int level[M],iter[M],a[N],cnt;
bool inq[M];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[N+M+2];

void add_edge1(int a,int b,int c){
    graph[0].push_back({now1,(int)graph[now1].size(),a});
    graph[now1].push_back({0,(int)graph[0].size()-1,0});

    graph[now1].push_back({m+b,(int)graph[m+b].size(),INF});
    graph[m+b].push_back({now1,(int)graph[now1].size()-1,0});

    graph[now1].push_back({m+c,(int)graph[m+c].size(),INF});
    graph[m+c].push_back({now1,(int)graph[now1].size()-1,0});
}

void add_edge2(int a){
    graph[m+now2].push_back({m+n+1,(int)graph[m+n+1].size(),a});
    graph[m+n+1].push_back({m+now2,(int)graph[m+now2].size()-1,0});
}

bool bfs(int s,int t){
    queue<int> q;
    q.push(s);
    inq[s]=true;

    memset(level,-1,sizeof(level));
    level[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;

        for(auto &e:graph[x])
        {
            if(e.cap>0&&level[e.to]==-1)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
                inq[e.to]=true;
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
        if(graph[u][i].cap>0&&level[graph[u][i].to]==level[u]+1)
        {
            int flow=dfs(graph[u][i].to,t,min(f,graph[u][i].cap));
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

int max_flow(int s,int t){
    int flow=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        int f=dfs(s,t,INF);
        while(f>0){
            flow+=f;
            f=dfs(s,t,INF);
        }
    }

    return flow;
}

int main(){
    cin>>m>>n;

    now1=0;
    sum=0;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        now1++;
        add_edge1(a,b,c);

        sum+=a;
    }

    now2=0;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        now2++;
        add_edge2(a);
    }

    /*for(int i=0;i<m+n+2;i++)
        for(int j=0;j<graph[i].size();j++)
            cout<<i<<" "<<graph[i][j].to<<" "<<graph[i][j].rev<<" "<<graph[i][j].cap<<" "<<endl;
    */

    cout<<sum-max_flow(0,m+n+1)<<endl;

    return 0;
}