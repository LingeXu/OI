#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define N 1510
#define M 1510
using namespace std;
int n,m;
int in_deg[N*M];
bool vis[N*M];
struct edge{
    int to;
    bool IsReachable;
};
struct xy{
    int x,y;
};
vector<edge> g[N*M];
vector<int> margin;
vector<xy> position;
/*void Kahn(int node){
    int cnt=0;
    memset(in_deg,0,sizeof(in_deg));
    for(int i=1;i<=n*m;i++)
        for(int j=0;j<g[i].size();j++)
            if(g[i][j].IsReachable==true)
                in_deg[g[i][j].to]++;
    queue<int> q;
    for(int i=1;i<=n*m;i++){
        if(in_deg[i]==0){
            q.push(i);    
            cnt++;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++){
            if(--in_deg[g[x][i].to]==0){
                q.push(g[x][i].to);
                cnt++;
                cout<<g[x][i].to<<" ";
            }
        }
    }
    if(cnt==node)
        cout<<"No"<<'\n';
    else if(cnt!=node)
        cout<<"Yes"<<'\n';
}*/
/*void dfs(int u){
    vis[u]=true;
    if(g[u].size()<4)
        margin.push_back(u);
    for(auto e:g[u])
        if(!vis[e.to]&&e.IsReachable==true)
            dfs(e.to);
}*/
void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(g[x].size()<4)
            margin.push_back(x);
        for(edge &e:g[x]){
            if(!vis[e.to]&&e.IsReachable==true){
                q.push(e.to);
                vis[e.to]=true;
            }
        }
    }
}
void judge(){
    for(int i=0;i<margin.size();i++)
        position.push_back({(margin[i]-1)/m+1,(margin[i]-1)%m+1});
    for(int i=0;i<position.size();i++){
        for(int j=i+1;j<position.size();j++){
            bool same_row=(position[i].x==position[j].x)&&((position[i].y==1&&position[j].y==m)||(position[i].y==m&&position[j].y==1)),same_col=(position[i].y==position[j].y)&&((position[i].x==1&&position[j].x==n)||(position[i].x==n&&position[j].x==1));
            if(same_row||same_col){
                cout<<"Yes"<<'\n';
                return;
            }
        }
    }
    cout<<"No"<<'\n';
    return;
}
int main(){
    while(cin>>n>>m){
        char c[N][M];
        int node=0,start;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
                if(c[i][j]!='#')
                    node++;
                if(c[i][j]=='S')
                    start=i*m+j+1;
            }
        }
        for(int i=1;i<=n*m;i++)
            g[i].clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0)
                    g[i*m+j+1].push_back({(i-1)*m+j+1,false});
                if(i<n-1)
                    g[i*m+j+1].push_back({(i+1)*m+j+1,false});
                if(j>0)
                    g[i*m+j+1].push_back({i*m+j,false});   
                if(j<m-1)
                    g[i*m+j+1].push_back({i*m+j+2,false});          
            }
        }
        for(int i=1;i<=n*m;i++)
            for(int j=0;j<g[i].size();j++)
                if(c[(i-1)/m][i-(i-1)/m*m-1]!='#'&&c[(g[i][j].to-1)/m][g[i][j].to-(g[i][j].to-1)/m*m-1]!='#')
                    g[i][j].IsReachable=true;  
        //cout<<node<<'\n';
        //Kahn(node);
        memset(vis,0,sizeof(vis));
        margin.clear();
        position.clear();
        bfs(start);
        /*for(int i=0;i<margin.size();i++)
            cout<<margin[i]<<" ";*/
        judge();
    }
    return 0;
}