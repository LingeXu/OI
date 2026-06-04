#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 1010
using namespace std;
int n;
int price[N], dist[N], method[N];
bool vis[N];
vector< pair<int, int> > graph[N];
void dijkstra(){
    memset(vis, 0, sizeof(vis));
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > >  pq;
    for(int i = 0; i < n; i++)
        pq.push({price[i], i});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(vis[x.second])   continue;
        vis[x.second] = true;
        for(int i = 0; i < n; i++){
            for(auto &e : graph[i]){
                /*if(e.first == x.second){
                    if(dist[x.second] + dist[e.second] < dist[i]){
                        dist[i] = dist[x.second] + dist[e.second];
                        method[i] = method[x.second] * method[e.second];
                        pq.push({dist[i], i});
                    }
                    else if(dist[x.second] + dist[e.second] == dist[i])
                        method[i] += method[x.second] * method[e.second];
                }
                else if(e.second == x.second){
                    if(dist[x.second] + dist[e.first] < dist[i]){
                        dist[i] = dist[x.second] + dist[e.first];
                        method[i] = method[x.second] * method[e.first];
                        pq.push({dist[i], i});
                    }
                    else if(dist[x.second] + dist[e.first] == dist[i])
                        method[i] += method[x.second] * method[e.first];
                }*/

                int a = e.first;
                int b = e.second;
                if((x.second == a || x.second == b) && vis[a] && vis[b]){
                    if(dist[a] + dist[b] < dist[i]){
                        dist[i] = dist[a] + dist[b];
                        method[i] = method[a] * method[b];
                        pq.push({dist[i], i});
                    }
                    else if(dist[a] + dist[b] == dist[i])
                        method[i] += method[a] * method[b];
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> price[i];
        dist[i] = price[i];
        method[i] = 1;
    }
    int a, b, c;
    while(cin >> a >> b >> c)   graph[c].push_back({a, b});
    dijkstra();
    cout << dist[0] << ' ' << method[0];
    return 0;
}