#include <bits/stdc++.h>
#define N 5050
using namespace std;
int n, m;
int dist[N], update_cnt[N];
bool inq[N];
vector< pair<int, int> > graph[N];
bool spfa() {
    memset(dist, -0x3f, sizeof(dist));
    queue<int> q;
    q.push(0);
    inq[0] = true;
    dist[0] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto& e : graph[x]) {
            if(dist[e.second] < dist[x] + e.first) {
                dist[e.second] = dist[x] + e.first;
                if(++update_cnt[e.second] > n)
                    return false;
                if(!inq[e.second]) {
                    q.push(e.second);
                    inq[e.second] = true;
                }
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 3) {
            graph[a].push_back({0, b});
            graph[b].push_back({0, a});
        }
        else if(op == 1) {
            int c;
            cin >> c;
            graph[a].push_back({c, b});
        }
        else if(op == 2) {
            int c;
            cin >> c;
            graph[b].push_back({-c, a});
        }
    }
    for(int i = 1; i <= n; i++)
        graph[0].push_back({0, i});
    cout << (spfa() == true ? "Yes" : "No");
    return 0;
}