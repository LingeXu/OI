#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> a1(n, -1), b1(n, n);
    stack< pair<int, int> > s1, s2;
    for(int i = 0; i < n; i++) {
        while(!s1.empty() && a[i] > s1.top().second) {
            b1[s1.top().first] = i;
            s1.pop();
        }
        s1.push(make_pair(i, a[i]));
    }
    for(int i = n - 1; i >= 0; i--) {
        while(!s2.empty() && a[i] > s2.top().second) {
            a1[s2.top().first] = i;
            s2.pop();
        }
        s2.push(make_pair(i, a[i]));
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int a_1 = a1[i], b_1 = b1[i];
        int a_2 = (a_1 == -1 ? -1 : a1[a_1]), b_2 = (b_1 == n ? n : b1[b_1]);
        //cout << "a_1 = " << a_1 << ", b_1 = " << b_1 << '\n';
        //cout << "a_2 = " << a_2 << ", b_2 = " << b_2 << '\n';
        ans += (a_1 - a_2) * (b_1 - i) * (i - a_1);
        ans += (b_2 - b_1) * (i - a_1) * (b_1 - i);
        //cout << "i = " << i << '\n';
        //cout << "ans = " << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}