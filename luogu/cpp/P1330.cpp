#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE__<<']'<<#x<<" "<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define N 10010
using namespace std;
int level[N];
vector<int> graph[N];
void add_edge(int from,int to){
    graph[from].push_back(to);
    graph[to].push_back(from);
}
bool bfs(int u,int &cnt0,int &cnt1){
    level[u]=0;
    queue<int> q;
    q.push(u);
    cnt0=1,cnt1=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int &neighbor:graph[x]){
            if(level[neighbor]==-1){
                level[neighbor]=1-level[x];
                if(1-level[x]==0)
                    cnt0++;
                else
                    cnt1++;
                q.push(neighbor);
            }
            else if(level[neighbor]==level[x]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        add_edge(from,to);
    }
    int cnt=0,cnt0,cnt1;
    memset(level,-1,sizeof(level));
    for(int i=1;i<=n;i++){
        if(level[i]==-1){
            if(bfs(i,cnt0,cnt1)){
                //cout<<count(level,level+n,0)<<" "<<count(level,level+n,1)<<'\n';
                cnt+=min(cnt0,cnt1);
            }
            else{
                cout<<"Impossible";
                return 0;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<graph[i].size();j++){
            if(level[i]==level[graph[i][j]]){
                cout<<"Impossible";
                return 0;
            }
        }
    }*/
    cout<<cnt;
    return 0;
}