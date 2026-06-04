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
int level[N*N];

struct grid{
    int x,y;
    char val;
}g[N*N];

int record(int x,int y){
    return (x-1)*n+y;
}

vector<int> graph[N*N];

void add_edge(int x,int y){
    graph[x].push_back(y);
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    memset(level,-1,sizeof(level));
    level[u]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int &neighbor:graph[x]){
            if(level[neighbor]==-1){
                level[neighbor]=level[x]+1;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(g[record(i,j)].val==0||g[record(i,j)].val==1)
                cin>>g[record(i,j)].val;
            //debug(g[record(i,j)].val);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[record(i,j)].x=i,g[record(i,j)].y=j;

    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<record(i,j)<<" "<<g[record(i,j)].x<<" "<<g[record(i,j)].y<<" "<<g[record(i,j)].val<<'\n';*/

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-1>=1)
                if(g[record(i,j)].val!=g[record(i-1,j)].val)
                    add_edge(record(i,j),record(i-1,j));
            if(i+1<=n)
                if(g[record(i,j)].val!=g[record(i+1,j)].val)
                    add_edge(record(i,j),record(i+1,j));   
            if(j-1>=1)
                if(g[record(i,j)].val!=g[record(i,j-1)].val)
                    add_edge(record(i,j),record(i,j-1));    
            if(j+1<=n)
                if(g[record(i,j)].val!=g[record(i,j+1)].val)
                    add_edge(record(i,j),record(i,j+1));
        }
    }

    /*for(int i=1;i<=n*n;i++)
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<'\n';*/
    int cnt=0;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if(i==1){
            bfs(record(x,y));
            for(int j=1;j<=n*n;j++)
                if(level[j]!=-1)
                    cnt++;
            cout<<cnt<<'\n';
        }
        else if(i!=1&&level[record(x,y)]!=-1)
            cout<<cnt<<'\n';
        else if(i!=1&&level[record(x,y)==-1]){
            cnt=0;
            bfs(record(x,y));
            for(int j=1;j<=n*n;j++)
                if(level[j]!=-1)
                    cnt++;
            cout<<cnt<<'\n';     
        }
    }

    return 0;
}