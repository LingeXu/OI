#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    int odd_cnt = 0, even_cnt = 0, odd_mx = 0, sum = 0;
    priority_queue<int, vector<int>, less<int>> even;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if(!(x & 1)) {
            even.push(x);
        }
        else {
            odd_cnt++;
            odd_mx = max(odd_mx, x);
        }
    }
    even_cnt = n - odd_cnt;
    if(odd_cnt == 0) {
        for(int i = 0; i < n; i++)
            cout << 0 << ' ';
        cout << '\n';
        return;
    }
    vector<int> ans(n + 1);
    ans[1] = odd_mx;
    for(int i = 2; i <= even_cnt + 1; i++) {
        ans[i] = ans[i - 1] + even.top();
        even.pop();
    }
    for(int i = even_cnt + 2; i <= n; i++) {
        //cout << "i = " << i << '\n';
        ans[i] = ans[i - 2];
    }
    if(sum % 2 == 0)
        ans[n] = 0;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}