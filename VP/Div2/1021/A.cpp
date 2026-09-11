#include <bits/stdc++.h>
using namespace std;
int t;
string s;
void solve() {
    cin >> s;
    string ans;
    map<int, int> mp;
    for(char c : s) {
        int num = c - '0';
        mp[num]++;
    }
    for(int i = 1; i <= 10; i++) {
        int least = 10 - i;
        while(mp[least] == 0 && least < 9) {
            least++;
        }
        mp[least]--;
        ans += (least + '0');
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}