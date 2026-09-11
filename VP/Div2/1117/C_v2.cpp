#include <bits/stdc++.h>
using namespace std;
int t, n, m;
void solve() {
    cin >> n;
    vector<int> depth(n + 1);
    depth[1] = 1;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        depth[i] = depth[x] + 1;
    }
    cin >> m;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        pq.push(make_pair(x, depth[x]));
    }
    cout << m - 1 << ' ';
    pq.pop();
    while(!pq.empty()) {
        cout << pq.top().first << ' ';
        pq.pop();
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}