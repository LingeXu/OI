#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
void solve() {
    cin >> n >> m >> k;
    vector<int> a(n), prefix(n), premin(n), sufmax(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if(i == 0) {
            prefix[i] = a[i];
            premin[i] = a[i];
        }
        else {
            prefix[i] = prefix[i - 1] + a[i];
            premin[i] = min(premin[i - 1], a[i]);
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1)  sufmax[i] = a[i];
        else    sufmax[i] = max(sufmax[i + 1], a[i]);
    }
    int round = m / sum;
    int remain = m - round * sum;
    if(remain == 0) {
        cout << round * n + (round - 1) * k << '\n';
        return;
    }
    else {
        for(int i = 0; i < n - 1; i++) {
            if(prefix[i] >= remain || prefix[i] - premin[i] + sufmax[i + 1] >= remain) {
                cout << round * n + round * k + i + 1 << '\n';
                return;
            }
        }
        cout << (round + 1) * n + round * k << '\n';
        return;
    }
}
signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}