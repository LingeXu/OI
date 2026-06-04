#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 101
#define INF 0x3f3f3f3f

using namespace std;

int n,sum;
double average;
int a[N],dist[N+2],prevv[N+2],preve[N+2];
bool inq[N+2];

struct edge{
    int to,rev,cap,cost;
};

vector<edge> graph[N+2];

void add_edge(int a,int b,int c,int d){
    graph[a].push_back({b,(int)graph[b].size(),c,d});
    graph[b].push_back({a,(int)graph[a].size()-1,0,-d});
}

bool spfa(int s,int t){
    queue<int> q;
    q.push(s);
    inq[s]=true;

    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;

        for(int i=0;i<graph[x].size();i++)
        {
            edge &e=graph[x][i];

            if(e.cap>0&&dist[e.to]>dist[x]+e.cost)
            {
                dist[e.to]=dist[x]+e.cost;
                prevv[e.to]=x;
                preve[e.to]=i;

                if(!inq[e.to])
                {
                    q.push(e.to);
                    inq[e.to]=true;
                }
            }
        }
    }

    return dist[t]!=INF;
}

int min_cost_max_flow(int s,int t){
    int flow=0,cost=0;

    while(spfa(s,t)){
        int f=INF;
        for(int i=t;i!=s;i=prevv[i])
            f=min(f,graph[prevv[i]][preve[i]].cap);
        
        flow+=f;
        cost+=f*dist[t];

        for(int i=t;i!=s;i=prevv[i])
        {
            graph[prevv[i]][preve[i]].cap-=f;
            graph[i][graph[prevv[i]][preve[i]].rev].cap+=f;
        }
    }

    return cost;
}

int main(){
    cin>>n;

    sum=0;

    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }  

    average=sum/n;

    for(int i=1;i<=n;i++)
    {
        if(a[i]>average)
            add_edge(0,i,a[i]-average,0);

        if(a[i]<average)
            add_edge(i,n+1,average-a[i],0);
    }

    for(int i=1;i<n;i++)
    {
        add_edge(i,i+1,INF,1);
        add_edge(i+1,i,INF,1);
    }
        
    add_edge(1,n,INF,1);
    add_edge(n,1,INF,1);

   /*for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" "<<graph[i][j].to<<" "<<graph[i][j].rev<<" "<<graph[i][j].cap<<" "<<graph[i][j].cost<<endl;
        }
    }*/

    cout<<min_cost_max_flow(0,n+1)<<endl;

    return 0;
}