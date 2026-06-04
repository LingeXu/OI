#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 110
using namespace std;
int n, m, ans = 0;
vector<int> tovisit;
vector< pair<int, int> > graph[N];
int dist[N];
void dijkstra(int s){
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(u > dist[v])
            continue;
        for(auto &e : graph[v]){
            if(dist[v] + e.first < dist[e.second]){
                dist[e.second] = dist[v] + e.first;
                pq.push({dist[e.second], e.second});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        tovisit.push_back(a);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int danger;
            cin >> danger;
            graph[i].push_back({danger, j});
        }
    }
    for(int i = 0; i < m - 1; i++){
        dijkstra(tovisit[i]);
        ans += dist[tovisit[i + 1]];
    }
    cout << ans;
    return 0;
}