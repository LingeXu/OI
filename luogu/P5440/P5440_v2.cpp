#include <bits/stdc++.h>
using namespace std;
int t, ans = 0;
string s;
bool ok = true;
int isprime[10010];
int DaysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> primes;
vector< pair<int, bool> > validMMDD;
vector<string> validString;
void euler_sieve(int n) {
    fill(isprime, isprime + n, true);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(isprime[i]) 
            primes.push_back(i);
        for(int p : primes) {
            if(p * i > n)   break;
            isprime[i * p] = false;
            if(i % p == 0)  break;
        }
    }
}
bool isPrime(int x) {
    if(x <= 9999)   return isprime[x];
    for(int i = 2; i * i <= x; i++) 
        if(x % i == 0) 
            return false;
    return true;
}
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void GetValidDate() {
    for(int i = 101; i <= 1231; i++) {
        if(i == 229) {
            validMMDD.push_back({i, true});
            continue;
        }
        int m = i / 100, d = i % 100;
        if(m > 12 || m == 0 || d > DaysOfMonth[m] || d == 0) continue;
        if(isprime[d] && isprime[i])
            validMMDD.push_back({i, false});
    }
}
void GetValidString() {
    for(auto i : validMMDD) {
        for(int j = 1; j <= 9999; j++) {
            int val = j * 10000 + i.first;
            if(!i.second && isPrime(val)) {
                string ans = to_string(val);
                while(ans.size() < 8)
                    ans = '0' + ans;
                validString.push_back(ans);
            }
            if(i.second && isLeap(j) && isPrime(val)) {
                string ans = to_string(val);
                while(ans.size() < 8)
                    ans = '0' + ans;
                validString.push_back(ans);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    euler_sieve(9999);
    GetValidDate();
    GetValidString();

    /*for(auto i : validMMDD)
        cout << i.first << ' ' << i.second << '\n';

    for(auto i : validString)
        cout << i << '\n';*/
        
    while(t--) {
        ans = 0;
        cin >> s;
        if(isdigit(s[7]) && !((s[7] - '0') & 1)) {
            cout << 0 <<'\n';
            continue;
        }
        if(s == "--------") {
            cout << validString.size() <<'\n';
            continue;
        }
        for(auto i : validString) {
            ok = true;
            for(int j = 0; j < 8; j++)  
                if(isdigit(i[j]) && isdigit(s[j]) && i[j] != s[j])
                    ok = false;
            if(ok)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}