#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 10010
#define K 15
#define INF 0x3f3f3f3f
using namespace std;
int n, m, k, s, t;
int dist[N * K];
bool vis[N * K];
vector< pair<int, int> > graph[N * K];
void dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u])  continue;
        vis[u] = true;
        for(auto &edge : graph[u]){
            if(dist[edge.second] > dist[u] + edge.first){
                dist[edge.second] = dist[u] + edge.first;
                pq.push({dist[edge.second], edge.second});
            }
        }
    }
}
int main(){
    cin >> n >> m >> k >> s >> t;
    for(int i = 1; i <= m; i++){
        int from, to, val;
        cin  >> from >> to >> val;
        for(int j = 0; j <= k; j++){
            graph[j * n + from].push_back({val, j * n + to});
            graph[j * n + to].push_back({val, j * n + from});
        }
        for(int j = 0; j < k; j++){
            graph[j * n + from].push_back({0, (j + 1) * n + to});
            graph[j * n + to].push_back({0, (j + 1) * n + from});
        }
    }
    dijkstra();
    //cout << "start=" << start << " end=" << end << endl;
    int ans = INF;
    for(int i = 0; i <= k; i++)
        ans = min(ans, dist[i * n + t]);
    cout << ans;
    return 0;
}