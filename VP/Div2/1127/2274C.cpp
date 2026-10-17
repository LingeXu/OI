#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool check(int x, int y) {
    int sum = 0;
    for(int i = 1; i <= x; i++) {
        sum += x / i * i;
        if(sum >= y)
            return true;
    }
    return false;
}
void solve() {
    cin >> n;
    int l = 1, r = n, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid, n)) {
            ans = mid;
            r = mid - 1;
        }
        else    l = mid + 1;
    }
    cout << ans << '\n';
    int cur = 1, remain = n, cur_ans = ans;
    while(remain > 0) {
        for(int j = cur; j < cur + ans / cur_ans; j++) {
            for(int i = 1; i <= min(remain, cur_ans); i++)
                cout << j << ' ';
            remain -= min(remain, cur_ans);
            if(remain == 0)
                break;
        }
        cur += ans / cur_ans;
        cur_ans--;
        //cout << "remain = " << remain << '\n';
        //cout << "cur = " << cur << '\n';
        //cout << "cur_ans = " << cur_ans << '\n';
    }
    cout << '\n';
}
signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}