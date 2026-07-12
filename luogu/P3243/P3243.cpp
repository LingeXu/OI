#include <bits/stdc++.h>
#define N 100010
using namespace std;
int t, n, m;
vector<int> graph[N], rev_ans;
int in_deg[N];
void topo_sort() {
    memset(in_deg, 0, sizeof(in_deg));
    for(int i = 1; i <= n; i++)
        for(int neighbor : graph[i])
            in_deg[neighbor]++;
    priority_queue<int, vector<int>, less<int> > pq;
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 0)
            pq.push(i);
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        rev_ans.push_back(x);
        for(int neighbor : graph[x])
            if(--in_deg[neighbor] == 0)
                pq.push(neighbor);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) 
            graph[i].clear();
        rev_ans.clear();
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            graph[v].push_back(u);
        }
        topo_sort();
        if(rev_ans.size() != n) {
            cout << "Impossible!\n";
            continue;
        }
        for(int i = n - 1; i >= 0 ; i--)
            cout << rev_ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}