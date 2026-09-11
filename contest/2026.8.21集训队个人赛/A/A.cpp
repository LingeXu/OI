#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> primes;
void euler_sieve(int x, vector<bool>& isprime) {
    for(int i = 2; i <= x; i++) {
        if(isprime[i])
            primes.push_back(i);
        for(int j : primes) {
            if(i * j > x)   break;
            isprime[i * j] = false;
            if(i % j == 0)  break;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int limit = cbrtl(n);
    while((limit + 1) * (limit + 1) * (limit + 1) <= n)    limit++;   
    vector<bool> isprime(limit + 10, true);
    euler_sieve(limit, isprime);
    int ans = 0;
    for(int i = 0; i < (int)primes.size(); i++) {
        int num = primes[i];
        int p = n / (num * num * num);
        //cout << num << ' ' << p << '\n';
        if(p < 2)   break;
        if(p >= num)    ans += i;
        else {
            auto it = upper_bound(primes.begin(), primes.end(), p);
            ans += (it - primes.begin());
        }
    }
    cout << ans;
    return 0;
}