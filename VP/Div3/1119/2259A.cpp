#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 1; i <= n / k; i++) {
            int l = (i - 1) * k, r = i * k - 1;
            //cout << "l = " << l << '\n';
            //cout << "r = " << r << '\n';
            bool ok = false;
            for(int j = l; j <= r; j++) {
                if(s[j] == '0') {
                    ok = true;
                    break;
                }
            }
            if(ok == false)  ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}