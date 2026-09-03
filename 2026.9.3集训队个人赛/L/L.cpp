#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n;
string s;
queue<int> k, u, p, c;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'K')
            k.push(i + 1);
        if(s[i] == 'U')
            u.push(i + 1);
        if(s[i] == 'P')
            p.push(i + 1);
        if(s[i] == 'C')
            c.push(i + 1);
    }
    int ans = 0;
    while(!k.empty() && !u.empty() && !p.empty() && !c.empty()) {
        if(c.front() > p.front() && p.front() > u.front() && u.front() > k.front()) {
            ans = (ans + k.front() * u.front() % MOD * p.front() % MOD * c.front() % MOD) % MOD;
            k.pop();
            u.pop();
            p.pop();
            c.pop();
            continue;
        }
        while(!p.empty() && c.front() < p.front())   p.pop();
        while(!u.empty() && c.front() < u.front())   u.pop();
        while(!k.empty() && c.front() < k.front())   k.pop();
        while(!u.empty() && p.front() < u.front())   u.pop();
        while(!k.empty() && p.front() < k.front())   k.pop();
        while(!k.empty() && u.front() < k.front())   k.pop();
    }
    cout << ans;
    return 0;
}