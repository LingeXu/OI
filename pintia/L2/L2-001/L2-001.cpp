#ifdef LOCAL
#define debug(x)    cout<<'['<<__LINE__<<']'<<" "<<#x<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define N 510
#define INF 0x3f3f3f3f

using namespace std;

int point_weight[N],dist[N],team_cnt[N],cnt[N];
bool vis[N];

struct edge{
    int to,to_val,cap;
};

vector<edge> graph[N];
vector<int> way[N];

void dijkstra(int u){
    memset(dist,0x3f,sizeof(dist));
    dist[u]=0;
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push({0,u});

    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();
        if(vis[x])  continue;
        vis[x]=true;

        for(auto &e:graph[x]){
            if(dist[e.to]>dist[x]+e.cap){
                dist[e.to]=dist[x]+e.cap;
                cnt[e.to]=cnt[x];
                team_cnt[e.to]=team_cnt[x]+point_weight[e.to];
                way[e.to]=way[x];
                way[e.to].push_back(e.to);
                pq.push({dist[e.to],e.to});
            }
            else if(dist[e.to]==dist[x]+e.cap){
                cnt[e.to]+=cnt[x];
                if(team_cnt[e.to]<team_cnt[x]+point_weight[e.to]){
                    way[e.to].clear();
                    way[e.to]=way[x];
                    way[e.to].push_back(e.to);
                }
                team_cnt[e.to]=max(team_cnt[e.to],team_cnt[x]+point_weight[e.to]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,s,d;
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++)    cin>>point_weight[i];

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        edge e1,e2;
        e1.to=b;
        e1.to_val=point_weight[b];
        e1.cap=c;
        e2.to=a;
        e2.to_val=point_weight[a];
        e2.cap=c;
        graph[a].push_back(e1);
        graph[b].push_back(e2);
    }

    memset(cnt,0,sizeof(cnt));
    cnt[s]=1;
    memset(team_cnt,0,sizeof(team_cnt));
    team_cnt[s]=point_weight[s];
    way[s].push_back(s);

    dijkstra(s);

    cout<<cnt[d]<<" "<<team_cnt[d]<<'\n';
    for(int i=0;i<way[d].size();i++){
        cout<<way[d][i];
        if(i!=way[d].size()-1)  cout<<" ";
    }

    return 0;
}