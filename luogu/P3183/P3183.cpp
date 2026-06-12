#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, m, ans = 0;
int in_deg[N], out_deg[N], cnt[N];
vector<int> graph[N], topo_sort, start;
void topo() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in_deg[i] == 0) {
            start.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()) {
        int x =q.front();
        q.pop();
        topo_sort.push_back(x);
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
        out_deg[from]++;
    }
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 0 && out_deg[i] == 0)
            ans--;
    topo();
    for(int i = 1; i <= n; i++)
        if(out_deg[i] == 0)
            cnt[i] = 1;
    for(int i = topo_sort.size() - 1; i >= 0; i--) 
        for(int to : graph[topo_sort[i]])
            cnt[topo_sort[i]] += cnt[to];
    for(int node : start)
        ans += cnt[node];
    cout << ans;
    return 0;
}