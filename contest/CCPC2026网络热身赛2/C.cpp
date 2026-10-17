#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];    
    priority_queue<int, vector<int>, less<int> > pq;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        pq.push(b[i]);
        cur += a[i];
        while(cur < 0) {
            if(pq.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            cur += pq.top();
            ans++;
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}