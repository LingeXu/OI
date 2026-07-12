#include <bits/stdc++.h>
#define N 1000010
const int K = 1 << 20;
using namespace std;
int n, k, ans = 1;
int a[N], level[K], in_deg[K];
bool exist[K], vis[K];
vector<int> graph[K], group[K];

/*void build() {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        for (int j = 0; j < k; j++) {
            if (x & (1 << j)) {
                int nxt = x ^ (1 << j); 
                if(exist[nxt])
                    level[x] = max(level[x], level[nxt] + 1);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        group[level[a[i]]].push_back(a[i]);
}*/

void build() {
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < k; i++) {
            if(((x >> i) & 1) == 0) {
                int v = x | (1 << i);
                graph[x].push_back(v);
                in_deg[v]++;
                if(vis[v])  continue;
                vis[v] = true;
                q.push(v);
            }
        }   
    }
}
void topo_sort() {
    memset(level, 0, sizeof(level));
    queue<int> q;
    q.push(0);
    if(exist[0]) {
        level[0] = 1;
        group[1].push_back(0);
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int j : graph[x]) {
            if(exist[j]) 
                level[j] = max(level[j], level[x] + 1);
            else    level[j] = max(level[j], level[x]);
            if(--in_deg[j] == 0) {
                if(exist[j]) 
                    group[level[j]].push_back(j);
                ans = max(ans, level[j]);
                q.push(j);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        exist[a[i]] = true;
        level[a[i]] = 1;
    }
    build();
    topo_sort();
    cout << 1 << '\n';
    cout << ans << '\n';
    for(int i = 1; i <= ans; i++) {
        cout << group[i].size();
        for(int j : group[i])
            cout << ' ' << j;
        cout << '\n';
    }
    return 0;
}