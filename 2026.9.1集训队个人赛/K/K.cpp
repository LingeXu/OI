#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(2 * n + 1);
    for(int i = 0; i < 2 * n; i++)
        cin >> a[i];
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    for(int i = 2 * n - 1; i >= 0; i--) {
        pq.push(make_pair(a[i], i));
        while((int)pq.size() > (2 * n - i) / 2)    pq.pop();
    }
    priority_queue<int, vector<int>, greater<int> > ans;
    while(!pq.empty()) {
        ans.push(pq.top().second + 1);
        pq.pop();
    }
    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();    
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}