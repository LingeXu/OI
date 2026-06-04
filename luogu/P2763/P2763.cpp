#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<sstream>

#define N 1001
#define K 21
#define INF 0x3f3f3f3f

using namespace std;

int k,n,sum=0;
int level[K+N+2],iter[K+N+2];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[K+N+2];

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

int dfs(int u,int t,int f){
    if(u==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[u];i<graph[u].size();i++)
    {
        edge &e=graph[u][i];

        if(e.cap>0&&level[e.to]==level[u]+1)
        {
            int d=dfs(e.to,t,min(f,e.cap));

            if(d>0)
            {
                e.cap-=d;
                graph[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }

    return 0;
}

int max_flow(int s,int t){
    int maxf=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        int d=dfs(s,t,INF);

        while(d>0){
            maxf+=d;
            d=dfs(s,t,INF);
        }
    }

    return maxf;
}

int main(){
    cin>>k>>n;

    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;

        sum+=x;

        add_edge(0,i,x);
    }

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        for(int j=1;j<=x;j++)
        {
            int a;
            cin>>a;

            add_edge(a,k+i,1);
        }

        add_edge(k+i,n+k+1,1);
    }

    /*for(int i=0;i<=k+n+1;i++)
        for(int j=0;j<graph[i].size();j++)
            cout<<i<<" "<<graph[i][j].to<<" "<<graph[i][j].cap<<endl;*/

    //cout<<max_flow(0,k+n+1)<<endl;

    if(max_flow(0,k+n+1)!=sum)
        printf("No Solution!\n");

    else
    {
        for(int i=1;i<=k;i++)
        {
            printf("%d:",i);
            for(int j=0;j<graph[i].size();j++)
            {
                edge &e=graph[i][j];

                if(e.cap==0&&e.to!=0)
                {
                    printf(" %d",e.to-k);
                }
            }

            cout<<endl;
        }
    }

    return 0;
}