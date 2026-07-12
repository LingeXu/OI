#include <bits/stdc++.h>
#define N 55
using namespace std;
int t, n, start, cnt = 0;
int deg[N], has_edge[N][N];
bool exist[N];
vector<int> graph[N];
vector<int> ans;
/*void topo_sort() {
    ans.clear();
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i < N; i++)
        if(exist[i] && in_deg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        exist[x] = false;
        for(int j : graph[x]) 
            if(--in_deg[j] == 0)
                q.push(j);
    }
    for(int i = 1; i < N; i++) {
        if(exist[i]) {
            cout << "some beads may be lost" << '\n';
            return;
        }
    }
    for(int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ans[i + 1] << '\n';
}*/
void dfs(int u) {
    for(int i : graph[u]) {
        if(has_edge[u][i] > 0) {
            has_edge[u][i]--;
            has_edge[i][u]--;
            dfs(i);
        }
    }
    ans.push_back(u);
}
void euler_circuit() {
    for(int i = 1; i < N; i++) {
        if(exist[i] && (deg[i] & 1)) {
            cout << "some beads may be lost" << '\n';
            return;
        }
    }
    for(int i = 1; i < N; i++) {
        if(exist[i]) {
            start = i;
            break;
        }
    }
    if(start == -1) {
        cout << "some beads may be lost" << '\n';
        return;
    }
    dfs(start);
    if((int)ans.size() - 1 != n) {
        cout << "some beads may be lost" << '\n';
        return;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cout << "Case #" << ++cnt << '\n';
        start = -1;
        memset(exist, 0, sizeof(exist));
        memset(deg, 0, sizeof(deg));
        memset(has_edge, 0, sizeof(has_edge));
        ans.clear();
        for(int i = 1; i < N; i++)
            graph[i].clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            exist[l] = exist[r] = true;
            graph[l].push_back(r);
            graph[r].push_back(l);
            deg[l]++;
            deg[r]++;
            has_edge[l][r]++;
            has_edge[r][l]++;
        }
        //topo_sort();
        euler_circuit();
        if(t != 0)
            cout << '\n';
    }
    return 0;
}