#include <bits/stdc++.h>
#define N 10000000
using namespace std;
vector<int> primes;
bool isprime[N];
void euler_sieve(int n) {
    for(int i = 2; i <= n; i++) {
        if(isprime[i] == true)  primes.push_back(i);
        for(int num : primes) {
            if(num * i > n)
                break;
            isprime[num * i] = false;
            if(i % num == 0)    break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= 9999999; i++)
        isprime[i] = true;
    euler_sieve(9999999);

    //for(int num : primes)   cout << num << ' ';

    for(int num : primes) {
        string dig;
        while(num != 0) {
            dig += (num % 10 + '0');
            num /= 10;
        }
        reverse(dig.begin(), dig.end());

        //cout << "dig = " << dig;

        if((int)s.size() != (int)dig.size())    continue;
        map<char, int> mp;
        vector<bool> occ(10, false);
        for(int i = 0; i < 26; i++)
            mp['a' + i] = -1;
        bool ok = true;
        for(int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if(mp[c] == -1 && occ[dig[i] - '0']) {
                ok = false;
                break;
            }
            if(mp[c] != -1 && dig[i] - '0' != mp[c]) {
                ok = false;
                break;
            }
            if(mp[c] == -1 && !occ[dig[i] - '0']) {
                mp[c] = dig[i] - '0';
                occ[dig[i] - '0'] = true;
                continue;
            }
        }
        if(ok) {
            cout << dig;
            return 0;
        }
    }
    cout << -1;
    return 0;
}