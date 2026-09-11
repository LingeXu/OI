#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        vector<int> exist(1010);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            exist[a[i]]++;
            ans += a[i];
        }
        int max_ex = 0, max_val = -1;
        for(int i = 0; i < n; i++) {
            if(exist[a[i]] > max_ex || (exist[a[i]] == max_ex && a[i] < max_val)) {
                max_ex = exist[a[i]];
                max_val = a[i];
            }
        }
        int shengxia = n - max_ex;
        if(max_ex - shengxia <= 2) {
            cout << ans << '\n';
            continue;
        }
        else {
            cout << ans - max_val * (max_ex - shengxia - 2) << '\n';
            continue;
        }
    }
    return 0;
}