#include <bits/stdc++.h>
using namespace std;
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if(n % 2 == 0) {
        int start = n / 2 - 1 - k / 2;
        int end = n - 1 - start;
        cout << a[end] - a[start] + 1 << '\n';
        return;
    }
    else {
        int start = n / 2 - (k + 1) / 2;
        int end = n - 1 - start;
        cout << a[end] - a[start] + 1 << '\n';
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}