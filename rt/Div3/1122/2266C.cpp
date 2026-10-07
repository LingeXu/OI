#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> pre0(n + 1), pre1(n + 1);
        pre0[0] = 0, pre1[0] = 0;
        for(int i = 0; i <n; i++) {
            if(s[i] == '0') {
                pre0[i + 1] = pre0[i] + 1;
                pre1[i + 1] = pre1[i];
                continue;
            }
            else {
                pre0[i + 1] = pre0[i];
                pre1[i + 1] = pre1[i] + 1;
                continue;
            }
        }
        if(s[0] == '1') {

            cout << pre0[n] << '\n';
            continue;
        }
        int ans = n;
        for(int i = 0; i < n; i++) {
            ans = min(ans, pre1[i + 1] + pre0[n] - pre0[i + 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}