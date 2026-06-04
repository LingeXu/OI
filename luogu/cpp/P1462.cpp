#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 10010
using namespace std;
int n, m, b;
int f[N], dist[N];
vector< pair<int, int> > all[N], graph[N];
void dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(x.first > dist[x.second])    continue;
        for(auto &e : graph[x.second]){
            if(dist[x.second] + e.first < dist[e.second]){
                dist[e.second] = dist[x.second] + e.first;
                pq.push({dist[e.second], e.second});
            }
        }
    }
}
bool check(int x){
    for(int i = 1; i <= n; i++)
        graph[i].clear();
    for(int i = 1; i <= n; i++){
        for(auto &e : all[i]){
            if(f[e.second] > x || f[i] > x)
                continue;
            graph[i].push_back(e);
        }
    }
    dijkstra();
    return dist[n] <= b ? 1 : 0;
}
int main(){
    cin >> n >> m >> b;
    for(int i = 1; i <= n; i++)
        cin >> f[i];
    for(int i = 1; i <= m; i++){
        int from, to, val;
        cin >> from >> to >> val;
        all[from].push_back({val, to});
        all[to].push_back({val, from});
    }
    int left = 0;
    int right = 1e9;
    int ans;
    if(!check(right)){
        cout << "AFK";
        return 0;
    }
    while(left <= right){
        int mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else    left = mid + 1;
    }
    cout << ans;
    return 0;
}