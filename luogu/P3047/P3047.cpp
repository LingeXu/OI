#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, k;
int c[N];
int level[N];
vector<int> graph[N];
int bfs(int start, int sum) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        sum += c[x];
        for(int to : graph[x]) {
            if(level[x] + 1 < level[to] && level[x] + 1 <= k) {
                level[to] = level[x] + 1;
                q.push(to);
            }
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++) {
        memset(level, 0x3f, sizeof(level));
        level[i] = 0;
        cout << bfs(i, 0) << '\n';
    }
    return 0;
}