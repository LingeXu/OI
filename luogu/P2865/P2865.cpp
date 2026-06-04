#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 5050
using namespace std;
int n, r;
int dist1[N], dist2[N];
vector< pair<int, int> > graph[N];
void dijkstra(){
    memset(dist1, 0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));
    dist1[1] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(x.first > dist2[x.second])   continue;
        for(auto &e : graph[x.second]){
            int u = e.first;
            int v = e.second;
            if(x.first + u < dist1[v]){
                dist2[v] = dist1[v];
                dist1[v] = x.first + u;
                pq.push({dist1[v], v});
            }
            else if(x.first + u > dist1[v] && x.first + u < dist2[v]){
                dist2[v] = x.first + u;
                pq.push({dist2[v], v});
            }
        }
    }
}
int main(){
    cin >> n >> r;
    for(int i = 1; i <= r; i++){
        int from, to, val;
        cin >> from >> to >> val;
        graph[from].push_back({val, to});
        graph[to].push_back({val, from});
    }
    dijkstra();
    cout << dist2[n];
    return 0;
}