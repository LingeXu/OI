#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector< tuple<int, int, int> >& x, int y, int k) {
    for(auto [a, b, c] : x) {
        if(a + b + c >= y)  continue;
        if(a - b > 0 || b - c > 0 || a - c > 0) 
            k -= (y - a - b - c);
        else {
            if(a == b && b == c)    return false;
            if(a == b)  k -= (2 + y - a - b - c);
            else    k -= (2 * min(b - a + 1, c - b + 1) + y - a - b - c);
        }
        if(k < 0)   return false;
    }
    return true;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector< tuple<int, int, int> > record;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        record.push_back({a, b, c});
    }
    int left = -4e18, right = 4e18, ans;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(check(record, mid, k)) {
            ans = mid;
            left = mid + 1;
        }
        else    right = mid - 1;
    }
    cout << ans << '\n';
}

signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}

