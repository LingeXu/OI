#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, k;
int parent[N], depth[N], max_depth[N];
vector<int> graph[N];
priority_queue< int, vector<int>, less<int> > pq;
void dfs(int u, int fa, int d) {
    parent[u] = fa;
    depth[u] = d;
    max_depth[u] = d;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs(v, u, d + 1);
        max_depth[u] = max(max_depth[u], max_depth[v]);
    }
}
int get_farthest(int x) {
    int res = x;
    memset(parent, 0, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    dfs(x, 0, 0);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > mx) {
            mx = depth[i];
            res = i;
        }
    }
    return res;
}
void solve() {
    int start = get_farthest(1);
    int end = get_farthest(start);
    int diameter = depth[end];

    //cout << diameter << '\n';
    
    int centre = end;

    int i = diameter >> 1;
    while(i > 0) {
        centre = parent[centre];
        i--;    
    }

    //cout << start << ' ' << end << ' ' << centre << '\n';

    dfs(centre, 0, 0);
    for(int i = 1; i <= n; i++) {
        if(i == centre)
            continue;
        pq.push(max_depth[i] - depth[i]);
    }
    int pop_cnt = 0;
    while(!pq.empty() && pop_cnt < k - 1) {
        pq.pop();
        pop_cnt++;
    }
    cout << pq.top() + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    solve();
    return 0;
}