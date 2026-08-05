#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    if(n == 2) {
        cout << 1 << ' ' << 2 << '\n';
        return;
    }
    if(n == 3) {
        cout << 1 << ' ' << 3 << ' ' << 2 << '\n';
        return;
    }
    vector<int> p(n + 1);
    p[n] = n - 1;
    p[n - 1] = 1;
    p[n - 2] = n;
    int cur_min = 2, cur_max = n - 2;
    for(int i = n - 3; i >= 1; i--) {
        if((n - i) & 1)
            p[i] = cur_min++;
        else    p[i] = cur_max--;
    }
    cout << p[n - 1] << ' ' << p[n];
    for(int i = 1; i < n - 1; i++)
        cout << ' ' << p[i];
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
        solve();
    return 0;
}