#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s, l;
    cin >> n >> s >> l;
    vector<int> a(n), presum(n);
    for(int i = 1; i <= n - 1; i++) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(i == s)  continue;
        if(i < s) {
            int dis = presum[s - 1] - presum[i - 1];
            if(dis > l) continue;
            if(dis <= l && 2 * dis > l) {
                ans = max(ans, s - i + 1);
                continue;
            }
            if(2 * dis <= l) {
                int remain = l - 2 * dis;
                int cur = s - i + 1;
                int now = s;

                //cout << "remain = " << remain << ' ' << "cur = " << cur << '\n';

                while(now < n && remain >= a[now]) {
                    remain -= a[now];
                    cur++;
                    now++;
                }
                ans = max(ans, cur);
            }
        }
        else if(i > s){
            int dis = presum[i - 1] - presum[s - 1];
            if(dis > l) break;
            if(dis <= l && 2 * dis > l) {
                ans = max(ans, i - s + 1);
                continue;
            }
            if(2 * dis <= l) {
                int remain = l - 2 * dis;
                int cur = i - s + 1;
                int now = s;
                while(now > 1 && remain >= a[now - 1]) {
                    remain -= a[now - 1];
                    cur++;
                    now--;
                }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans;
    return 0;
}