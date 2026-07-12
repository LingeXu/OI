#include <bits/stdc++.h>
#define N 110
typedef long long ll;
using namespace std;
int n, p;
bool ok = false;
struct Node {
    ll c,u;
    int in_deg, out_deg;
} node[N];
vector< pair<int, int> > graph[N];
void topo_sort() {
    for(int i = 1; i <= n; i++) {
        node[i].out_deg = graph[i].size();
        for(auto e : graph[i])
            node[e.second].in_deg++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(node[i].in_deg == 0 && node[i].c > 0)
            q.push(i);
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        if(node[x].out_deg == 0 && node[x].c > 0) {
            ok = true;
            cout << x << ' ' << node[x].c << '\n';
        }
        for(auto e : graph[x]) {
            node[e.second].c += (node[x].c > 0) * e.first * node[x].c;
            if(--node[e.second].in_deg == 0) {
                node[e.second].c -= node[e.second].u;
                q.push(e.second);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for(int i = 1; i <= n; i++) 
        cin >> node[i].c >> node[i].u;
    for(int i = 1; i <= p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    topo_sort();
    if(!ok)
        cout << "NULL";
    return 0;
}