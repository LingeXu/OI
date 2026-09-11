#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int bigger = 0, smaller = 0;
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                bigger++;
                continue;
            }
            if(a[j] < a[i]) {
                smaller++;
                continue;
            }
        }
        cout << max(bigger, smaller) << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}