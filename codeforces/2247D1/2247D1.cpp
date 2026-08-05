#include <bits/stdc++.h>
using namespace std;
int t, n, q;
bool in_order;
void solve() {
    in_order = true;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0 && a[i] > a[i - 1])   in_order = false;
    }
    if(in_order) {
        cout << 0 << '\n';
        return;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(t--)  solve();
    return 0;
}