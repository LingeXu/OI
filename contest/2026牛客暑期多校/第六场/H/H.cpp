#include <bits/stdc++.h>
using namespace std;
int t, n;
bool isprime(int x) {
    if(x == 1)  return false;
    if(x == 2)  return true;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return true;
    return false;
}
void solve() {
    cin >> n;
    if(n == 2) {
        cout << 1 << ' ' << 2 << '\n';
        return;
    }
    if(n == 3 || n == 4 || n == 6) {
        cout << -1 << '\n';
        return;
    }
    if(n & 1) {
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return; 
    }
    if(!(n & 1) && isprime(n - 1)) {
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return; 
    }
    else {
        for(int i = 1; i <= n - 4; i++) cout << i << ' ';
        cout << n << ' ' << n - 1 << ' ' << n - 2 << ' ' << n - 3 << '\n';
        return;
    }
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}