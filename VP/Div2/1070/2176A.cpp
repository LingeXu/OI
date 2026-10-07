#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, ans = 0;
    vector<bool> used(n);
    while(i < n) {
        if(used[i]) {
            i++;
            continue;
        }
        int j = i + 1;
        while(j < n) {
            if(!used[j] && a[i] > a[j]) {
                ans++;
                used[j] = true;
                
            }
            j++;
        }
        i++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}