#include <bits/stdc++.h>
#define int long long 
#define N 1000010
using namespace std;
int t, n, cnt = 0;
string s;
void solve() {
    cnt = 0;
    cin >> n >> s;
    // map< pair<int, int>, int> mp;
    /*for(int len = 2; len <= n; len++) {
        for(int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if(mp[make_pair(l, r - 1)] == 0 && s[r] == '1')
                mp[make_pair(l, r)] = 1;
            else if(mp[make_pair(l, r - 1)] == 1 && s[r] == '0')
                mp[make_pair(l, r)] = 0;
            else    mp[make_pair(l, r)] = -1;
            if(mp[make_pair(l, r)] != -1)   continue;
            int x = prefix[r + 1] - prefix[l];
            int y = r - l + 1 - x;
            if((x - y) % 3 != 0) {
                cnt++;

                //cout << l << ' ' << r << '\n';
                
            }
        }
    }*/
    //cout << cnt + n << '\n';
    int a[3] = {1, 0, 0};
    int x = 0, longest_altering_suffix = 0;
    char pre = '\0';
    for(char c : s) {
        if(c == '0')    x--;
        else    x++;
        x %= 3;
        if(x < 0)   x += 3;
        a[x]++;
        if(x == 0)  cnt += a[1] + a[2];
        else if(x == 1)  cnt += a[0] + a[2];
        else    cnt += a[0] + a[1];
        if(pre == '\0') longest_altering_suffix = 1;
        else if(pre != '\0' && c != pre)   longest_altering_suffix++;
        else    longest_altering_suffix = 1;
        pre = c;
        cnt -= (longest_altering_suffix - 1) / 2;
    }
    cout << cnt << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}