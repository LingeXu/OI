#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n + 1), diff(n + 2), presum(n + 2);
    set< pair<int, int> > goodivs, badivs;
    vector<bool> can_choose(n, false);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < a[i]; j++) {
            int l = min(n, j * i);
            int r = min(n, (j + 1) * i - 1);
            goodivs.push_back(make_pair(l, r));
        }
        badivs.push_back(make_pair(min(n, a[i] * i), min(n, (a[i] + 1) * i - 1)));
        diff[min(n, a[i] * i)]++;
        diff[min(n + 1, (a[i] + 1) * i)]--;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0)  presum[i] = diff[i];
        else    presum[i] = presum[i - 1] + diff[i];
        if(presum[i] == 0)  can_choose[i] = true;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}