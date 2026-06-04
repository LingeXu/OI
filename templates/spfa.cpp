vector< pair<int, int> > graph[N];
int dist[N], cnt[N];
bool inq[N];
void spfa(int s) {
    queue<int> q;
    q.push(s);
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    inq[s] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto& e : graph[x]) {
            if(dist[e.second] > dist[x] + e.first) {
                dist[e.second] = dist[x] + e.first;
                if(!inq[e.second]) {
                    q.push(e.second);
                    inq[e.second] = true;
                    if(++cnt[e.second] > n - 1) {
                        cout << "存在负环";
                        return;
                    }
                }
            }
        }
    }
}