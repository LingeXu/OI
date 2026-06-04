vector< pair<int, int> > graph[N];
void dijkstra(int s) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, s});
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if(x.first > dist[x.second])   continue;
        for(auto& e : graph[x.second]) {
            if(dist[e.second] > dist[x.second] + e.first) {
                dist[e.second] = dist[x.second] + e.first;
                pq.push({dist[e.second], e.second});
            }
        }
    }
}