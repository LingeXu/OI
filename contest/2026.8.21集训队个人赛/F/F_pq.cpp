#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if(pq.top() < x) {          
            ans += x - pq.top();
            pq.pop();
            pq.push(x);             
        }
    }
    cout << ans;
    return 0;
}
