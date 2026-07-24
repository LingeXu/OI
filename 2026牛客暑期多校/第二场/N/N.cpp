#include <bits/stdc++.h>
#define N 200020
typedef long long ll;
using namespace std;
int t, n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> k;
        ll a[N], s[N];
        for(int j = 1; j <= n; j++) 
            cin >> a[j];
        sort(a + 1, a + 1 + n);
        memset(s, 0, sizeof(0));
        for(int j = 1; j <= n; j++) 
            s[j] = s[j - 1] + a[j];
        if(k & 1) {
            int half = (k - 1) >> 1;
            ll change = -0x3f3f3f3f3f3f3f3f;
            for(int j = half + 2; j + half - 1 <= n; j++)
                change = max(change, (k - 1) * a[j - 1] - s[half] - (s[j + half - 1] - s[j - 1]));
            cout << change + s[n] << '\n';
        }
        else {
            int half = k / 2 - 1;
            ll change = -0x3f3f3f3f3f3f3f3f;
            //cout << half << '\n';
            for(int j = half + 3; j + half - 1 <= n; j++) 
                change = max(change, half * (a[j - 2] + a[j - 1]) - s[half] - (s[j + half - 1] - s[j - 1]));
            cout << change + s[n] << '\n';
        }
    }
    return 0;
}