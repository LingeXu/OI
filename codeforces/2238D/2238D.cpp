#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> primes;
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false; 
    for(int i = 2; i <= n; i++) {
        if(isprime[i])
            primes.push_back(i);
        for(int j : primes) {
            if(i * j > n)   break;
            isprime[i * j] = false;
            if(i % j == 0)  break;
        }
    }

    /*for(int i = 0; i < (int)primes.size(); i++)
        cout << primes[i] << ' ';
    cout << '\n';
    cout << '\n';*/

    int ans = 0, base = 0;
    for(int i = 0; i < (int)primes.size() && n != 1; i++) {
        int num = primes[i];
        bool first_time = true;
        while(n % num == 0) {
            n /= num;
            if(first_time) {
                base++;
                first_time = false;
            }
            ans++;
        }
    }
    cout << ans + base - 1 << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}