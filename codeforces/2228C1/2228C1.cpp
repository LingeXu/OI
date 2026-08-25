#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, a, n, x, y, ans = LLONG_MAX;
int update(int cur, int candidate) {
    return min(cur, abs(a - candidate));
}
void solve() {
    ans = LLONG_MAX;
    cin >> a >> n >> x >> y;
    if(a < 10) {
        cout << min(min(abs(a - x), abs(a - y)), min(abs(a - 10 * y - x), abs(a - 10 * x - x))) << '\n';
        return;
    }
    string s = to_string(a);
    int l = (int)s.size();
    int fi_diff = l, pre_x = -1, pre_y = -1;
    for(int i = 0; i < l; i++) {
        int num = s[i] - '0';
        if(num == x)    pre_x = i;
        else if(num == y)    pre_y = i;
        else{
            fi_diff = i;
            break;
        }
    }
    if(fi_diff == l) {
        cout << 0 << '\n';
        return;
    }
    int candidate1 = 0, val1 = y;
    for(int i = 0; i < l - 1; i++) {
        candidate1 += val1;
        val1 *= 10;
    }
    ans = update(ans, candidate1);
    string candidate2 = "";
    int val2 = x;
    candidate2 += (x == 0 ? (y + '0') : (x + '0'));
    while((int)candidate2.size() < l + 1)   candidate2 += (x + '0');
    ans = update(ans, stoll(candidate2));
    int digit = s[fi_diff] - '0';
    if(digit > y) {
        string smaller = s.substr(0, fi_diff);
        while((int)smaller.size() < l)  smaller += (y + '0');
        ans = update(ans, stoll(smaller));
        string bigger = "";
        if(pre_x != -1)
            bigger = s.substr(0, pre_x);
        bigger += (y + '0');
        while((int)bigger.size() < l)  bigger += (x + '0');
        ans = update(ans, stoll(bigger));
    }   
    else if(digit < x) {
        string bigger = s.substr(0, fi_diff);
        while((int)bigger.size() < l)  bigger += (x + '0');
        ans = update(ans, stoll(bigger));
        string smaller = "";
        if(pre_y != -1)
            smaller = s.substr(0, pre_y);
        smaller += (x + '0');
        while((int)smaller.size() < l)  smaller += (y + '0');
        ans = update(ans, stoll(smaller));
    }   
    else {
        string smaller = s.substr(0, fi_diff), bigger = smaller;
        smaller += (x + '0'), bigger += (y + '0');
        while((int)smaller.size() < l)  smaller += (y + '0');
        while((int)bigger.size() < l)  bigger += (x + '0');
        ans = update(ans, stoll(smaller));
        ans = update(ans, stoll(bigger));
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}