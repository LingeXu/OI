#include<iostream>
#include<vector>
#include<queue>
#define N 100010
using namespace std;
int n, m;
int price[N];
int dist[N];
vector<int> graph[N];
struct now{
    int earn, buy, sell, node;
};
auto cmp = [](now x, now y){return x.earn > y.earn || (x.earn == y.earn && x.buy < y.buy);};
void dijkstra(){
    memset(dist, 0, sizeof(dist));
    priority_queue< now, vector<now>, decltype(cmp)> pq(cmp);
    pq.push({0, price[1], price[1], 1});
    while(!pq.empty()){
        now x = pq.top();
        pq.pop();
        if(x.earn < dist[x.node])   continue;
        for(int neighbor : graph[x.node]){
            if(x.earn == 0 && price[neighbor] < x.buy){
                dist[neighbor] = 0;
                pq.push({0, price[neighbor], price[neighbor], neighbor});
                continue;
            }
            if(price[neighbor] > x.sell){
                dist[neighbor] = price[neighbor] - x.buy;
                pq.push({dist[neighbor], x.buy, price[neighbor], neighbor});
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
        graph[from].push_back(to);
        if(inf == 2)    graph[to].push_back(from);
    }
    dijkstra();
    cout << dist[n];
    return 0;
}