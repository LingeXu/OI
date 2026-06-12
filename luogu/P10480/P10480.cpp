#include <bits/stdc++.h>
#define N 30030
using namespace std;
int n, m;
int in_deg[N];
vector<int> graph[N];
vector<int> topo_order;
bitset<N> f[N];
void topo() {
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        topo_order.push_back(x);
        for(int to : graph[x])
            if(--in_deg[to] == 0)
                q.push(to);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        in_deg[to]++;
    }
    topo();
    for(int i = topo_order.size() - 1; i >= 0; i--) {
        int u = topo_order[i];
        f[u][u] = 1;
        for(int to : graph[u])
            f[u] |= f[to];
    }
    for(int i = 1; i <= n; i++)
        cout << f[i].count() << '\n';
    return 0;
}