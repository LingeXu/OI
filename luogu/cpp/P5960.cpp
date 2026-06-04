#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 5050
#define INF 0x3f3f3f3f
using namespace std;
int n, m;
int dist[N], cnt[N];
bool inq[N];
vector< pair<int, int> > graph[N];
bool spfa(){
    memset(inq, 0,sizeof(inq));
    memset(cnt, 0,sizeof(cnt));
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    inq[0] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto &e : graph[x]){
            if(dist[e.second] > dist[x] + e.first){
                dist[e.second] = dist[x] + e.first;
                cnt[e.second] = cnt[x] + 1;
                if(cnt[e.second] >= n + 1)  return false;
                if(!inq[e.second]){
                    q.push(e.second);
                    inq[e.second] = true;
                }
            }
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int to, from, val;
        cin >> to >> from >> val;
        graph[from].push_back({val, to});
    }
    for(int i = 1; i <= n; i++)
        graph[0].push_back({0, i});
    if(!spfa())
        cout << "NO";
    else {
        for(int i = 1; i <= n; i++)
            cout << dist[i] << ' ';
    }
    return 0;
}