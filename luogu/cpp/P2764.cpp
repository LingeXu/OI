#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

#define N 151
#define INF 0x3f3f3f3f

using namespace std;

int n,m;
int dist[2*N+2],level[2*N+2],iter[2*N+2],has_in[N],match[N];
bool inq[2*N+2],vis[2*N+2];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[2*N+2];

void add_edge(int a,int b,int c){
    graph[a].push_back({b,(int)graph[b].size(),c});
    graph[b].push_back({a,(int)graph[a].size()-1,0});
}

bool bfs(int s,int t){
    memset(level,-1,sizeof(level));
    level[s]=0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(int i=0;i<graph[x].size();i++)
        {
            edge &e=graph[x][i];
            if(e.cap>0&&level[e.to]==-1)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
            }
        }
    }

    return level[t]!=-1;
}

int dfs(int s,int t,int f){
    if(s==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[s];i<graph[s].size();i++)
    {
        edge &e=graph[s][i];

        if(e.cap>0&&level[e.to]==level[s]+1)
        {
            int flow=dfs(e.to,t,min(f,e.cap));
            if(flow>0)
            {
                e.cap-=flow;
                graph[e.to][e.rev].cap+=flow;
                /*has_in[e.to-n]=true;
                match[s]=e.to-n;*/
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
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        add_edge(x,n+y,1);
    }

    for(int i=1;i<=n;i++)
    {
        add_edge(0,i,1);
        add_edge(n+i,2*n+1,1);
    }

    /*for(int i=0;i<=2*n+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" "<<graph[i][j].to<<endl;
        }
    }*/

    int maxf=max_flow(0,2*n+1);

    /*for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            printf("%d",i);

            int now=i;
            while(!vis[now])
            {
                vis[now]=true;
                for(int j=0;j<graph[now].size();j++)
                {
                    edge &e=graph[now][j];

                    if(e.cap==0&&!vis[e.to]&&e.to!=0)
                    {
                        now=e.to-n;
                        vis[e.to]=true;
                        printf(" %d",e.to-n);
                        break;
                    }

                }
            }
            printf("\n");
        }
    }*/

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            edge &e=graph[i][j];

            if(e.cap==0&&e.to!=0)
            {
                has_in[e.to-n]=true;
                match[i]=e.to-n;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        int now=i;
        if(!has_in[now]) 
        {
            printf("%d ",now);
        
            now=match[now];
            while(now!=0){
                printf("%d ",now);
                now=match[now];
            }

            printf("\n");
        }
    }

    printf("%d",n-maxf);

    return 0;
}