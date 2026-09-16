#include <bits/stdc++.h>
using namespace std;
int t, n, k, p, m;
void solve() {
    cin >> n >> k >> p >> m;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    queue< pair<int, int> > q;
    int record;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(i == p - 1)  record = a;
        if(i < k)   pq.push(make_pair((i != p - 1), a));
        else    q.push(make_pair((i != p - 1), a));
    }
    if(n == k) {
        cout << m / record << '\n';
        return;
    }
    int cnt = 0;
    while(m >= pq.top().second) {
        auto x = pq.top();
        pq.pop();
        m -= x.second;
        pq.push(q.front());
        q.pop();
        q.push(x);
        if(x.first == 0)    cnt++;
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}