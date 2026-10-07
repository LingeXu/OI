#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int t, n, c;
string s;
int gcd(int a, int b) {
    if(a == 0)  return b;
    else    return gcd(b % a, a);
}
bool isexponent(int num) {
    while(num != 1) {
        if(num & 1)
            return false;
        num /= 2;
    }
    return true;
}
void solve() {
    cin >> n >> c >> s;
    if(s[0] == '0' || s[n - 1] == '0') {
        cout << -1 << '\n';
        return;
    }
    if(s[0]== '?')
        s[0] = '1';
    if(s[n - 1]== '?')
        s[n - 1] = '1';
    if(s[1] == '?')
        s[1] = '0';
    int ans = 2, cur = 2 % c;
    vector<int> to_judge;
    for(int i = 1; i < n - 1; i++) {
        if(s[i] == '?') {
            to_judge.push_back(i);
        }
        else {
            if(s[i] == '0') {
                ans = ans * i % MOD;
                cur = cur * (i % c) % c;
            }
            else {
                ans = ans * 2 % MOD;
                cur = cur * (2 % c) % c;
            }
            if(cur == 0) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    int remain = c / gcd(cur, c);
    if(remain == 1) {
        cout << -1 << '\n';
        return;
    }
    if(!isexponent(remain)) {
        for(int i : to_judge) 
            ans = ans * 2 % MOD;
        cout << ans << '\n';
        return;
    }
    else {
        if((int)to_judge.size() <= 30 && remain > (1LL << (int)to_judge.size())) {
            for(int i : to_judge) 
                ans = ans * 2 % MOD;
            cout << ans << '\n';
            return;
        }
        else {
            for(int i : to_judge) {
                if(i % 2 == 0) {
                    ans = ans * 2 % MOD;
                    remain /= 2;
                    if(remain == 1) {
                        cout << -1 << '\n';
                        return;
                    }
                }
            }
            for(int i = (int)to_judge.size() - 1; i >= 0; i--) {
                if(to_judge[i] % 2 == 0)    continue;
                if(remain > 2) {
                    ans = ans * 2 % MOD;
                    remain /= 2;
                }
                else {
                    ans = ans * to_judge[i] % MOD;
                }
            }
        }
        cout << ans << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}