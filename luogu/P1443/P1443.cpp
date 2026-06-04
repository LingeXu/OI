#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE__<<']'<<" "<<#x<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<vector>
#include<queue>
#define N 410
#define M 410
#define INF 0x3f3f3f3f
using namespace std;
int n,m,x,y;
int dist[N*M];
bool vis[N*M];
struct edge{
    int to,weight;
};
vector<edge> graph[N*M];
int record(int x,int y){
    return (x-1)*m+y;
}
void add_edge(int x,int y){
    graph[x].push_back({y,1});
    graph[y].push_back({x,1});
}
void dijkstra(int u){
    memset(dist,0x3f,sizeof(dist));
    dist[u]=0;
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,u});
    while(!pq.empty()){
        auto e=pq.top();
        pq.pop();
        int fi=e.first,se=e.second;
        if(vis[se])
            continue;
        vis[se]=true;
        for(auto &e:graph[se]){
            if(dist[e.to]>dist[se]+e.weight){
                dist[e.to]=dist[se]+e.weight;
                pq.push({dist[e.to],e.to});
            }
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i-1>=1&&j-2>=1)
                add_edge(record(i,j),record(i-1,j-2));
            if(i-2>=1&&j-1>=1)
                add_edge(record(i,j),record(i-2,j-1));
            if(i-2>=1&&j+1<=m)
                add_edge(record(i,j),record(i-2,j+1));
            if(i-1>=1&&j+2<=m)
                add_edge(record(i,j),record(i-1,j+2));
            if(i+1<=n&&j-2>=1)
                add_edge(record(i,j),record(i+1,j-2));
            if(i+2<=n&&j-1>=1)
                add_edge(record(i,j),record(i+2,j-1));
            if(i+2<=n&&j+1<=m)
                add_edge(record(i,j),record(i+2,j+1));
            if(i+1<=n&&j+2<=m)
                add_edge(record(i,j),record(i+1,j+2));
        }
    }

    int start=record(x,y);
    dijkstra(start);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dist[record(i,j)]!=INF)
                cout<<dist[record(i,j)]<<" ";
            else    cout<<-1<<" ";
        }
        cout<<'\n';
    }

    return 0;
}