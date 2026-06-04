#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 100010
using namespace std;
int n, m;
int price[N], dist[3 * N];
bool inq[3 * N];
vector< pair<int, int> > graph[3 * N];
void spfa(){
    memset(dist, -0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    inq[1] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto& e : graph[x]){
            if(dist[x] + e.first > dist[e.second]){
                dist[e.second] = dist[x] + e.first;
                if(!inq[e.second]){
                    q.push(e.second);
                    inq[e.second] = true;
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> price[i];
    for(int i = 1; i <= m; i++){
        int from, to, inf;
        cin >> from >> to >> inf;
        for(int j = 1; j <= 3; j++){
            graph[(j - 1) * n + from].push_back({0, (j - 1) * n + to});
            if(inf == 2)
                graph[(j - 1) * n + to].push_back({0, (j - 1) * n + from});
        }
    }
    for(int i = 1; i <= n; i++){
        graph[i].push_back({-price[i], n + i});
        graph[n + i].push_back({price[i], 2 * n + i});
    }
    spfa();
    cout << dist[3 * n];
    return 0;
}