#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE__<<"]"<<" "<<#x<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 1010
#define M 100010
using namespace std;

int n,m;
int fa[N*N],sz[N*N];

struct grid{
    int x,y;
    char val;
}g[N*N];

int record(int x,int y){
    return (x-1)*n+y;
}

struct edge{
    int from,to,id;
};

vector<edge> graph;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry){
        fa[rx]=ry;
        sz[ry]+=sz[rx];
    }

}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            g[record(i,j)].val=c;
            //debug(g[record(i,j)].val);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[record(i,j)].x=i,g[record(i,j)].y=j;

    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<record(i,j)<<" "<<g[record(i,j)].x<<" "<<g[record(i,j)].y<<" "<<g[record(i,j)].val<<'\n';*/

    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-1>=1)
                if(g[record(i,j)].val!=g[record(i-1,j)].val)
                    graph.push_back({record(i,j),record(i-1,j),++cnt});
            if(i+1<=n)
                if(g[record(i,j)].val!=g[record(i+1,j)].val)
                    graph.push_back({record(i,j),record(i+1,j),++cnt});   
            if(j-1>=1)
                if(g[record(i,j)].val!=g[record(i,j-1)].val)
                    graph.push_back({record(i,j),record(i,j-1),++cnt});     
            if(j+1<=n)
                if(g[record(i,j)].val!=g[record(i,j+1)].val)
                    graph.push_back({record(i,j),record(i,j+1),++cnt}); 
        }
    }

    /*for(int i=1;i<=n*n;i++)
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<'\n';*/

    for(int i=1;i<=n*n;i++){
        fa[i]=i;
        sz[i]=1;
    }


    for(int i=0;i<graph.size();i++){
        unite(graph[i].from,graph[i].to);
    }

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;

        cout<<sz[find(record(x,y))]<<'\n';
    }
    return 0;
}