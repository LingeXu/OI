#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        a[n] = 1;
        int sum = n * (n + 1) / 2 - 1; 
        for(int i = 2; i < n; i += 2) {
            a[i] = i + 1;
            sum -= (i + 1);
        }
        for(int i = 3; i < n; i += 2) {
            a[i] = i - 1;
            sum -= (i - 1);
        }
        a[1] = sum;
        if(sum + 1 > n) {
            int cnt = 0;
            while(!(sum & 1)) {
                sum >>= 1;
                cnt++;
            }
            swap(a[1], a[(1 << cnt)]);
            if(a[1] == 1) {
                cout << -1 << '\n';
                continue;
            }
            for(int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
        else {
            for(int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}