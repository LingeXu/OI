#include <bits/stdc++.h>
using namespace std;
int t, n = 0, ans = 0;
int a, b, c;
int DaysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> vacant;
bool isPrime(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++) 
        if(x % i == 0)
            return false;
    return true;
}
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool validDate(int x) {
    int day = x % 100;
    int month = x % 10000 / 100;
    int year = x / 10000;
    if(day > 31 || month > 12 || day == 0 || month == 0 || year == 0) return false;
    if(isLeap(year) && month == 2) {
        if(day > 29) return false;
    }
    else {
        if(day > DaysOfMonth[month]) return false;
    }
    return true;
}
void dfs(int u) {
    if(u == n) {
        if(isPrime(a) && isPrime(b) && isPrime(c) && validDate(a)) 
            ans++;
        return;
    }
    int bit = vacant[u];
    int power = 1;
    for(int i = 0; i < bit; i++) 
        power *= 10;
    for(int i = 0; i <= 9; i++) {
        if(bit <= 1)
            c += i * power;
        if(bit <= 3)
            b += i * power;
        a += i * power;
        if(bit <= 1 && ((u + 1 < n && vacant[u + 1] > 1) || u + 1 == n )) {
            if(c > 31 || c == 0 || !isPrime(c)) {
                c -= i * power;
                b -= i * power;
                a -= i * power;
                continue;
            }
        }
        if(bit <= 3 && ((u + 1 < n && vacant[u + 1] > 3) || u + 1 == n )) {
            if(b / 100 > 12 || b / 100 == 0 || !isPrime(b)) {
                b -= i * power;
                a -= i * power;
                continue;
            }
        }
        dfs(u + 1);
        if(bit <= 1)
            c -= i * power;
        if(bit <= 3)
            b -= i * power;
        a -= i * power;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    string s;
    while(t--) {
        n = ans = 0;
        a = b = c = 0;
        vacant.clear();
        cin >> s;
        if(isdigit(s.back()) && !((s.back() - '0') & 1)) {
            cout << 0 << '\n';
            continue;
        }
        for(int i = 0; i < 8; i++) {
            if(s[i] == '-') {
                n++;
                vacant.push_back(7 - i);
                continue;
            }
            int num = s[i] - '0';
            int power = 1;
            for(int j = 0; j < 7 - i; j++) 
                power *= 10;
            if(i >= 6)
                c += num * power;
            if(i >= 4)
                b += num * power;
            a += num * power;
        }
        if(vacant.size() == 8) {
            for(int i = 10101; i <= 99991231; i += 2) 
                if(i % 10000 / 100 < 12 && i % 100 <= 31 && validDate(i) && isPrime(i) && isPrime(i % 100) && isPrime(i % 10000))
                    ans++;
            cout << ans << '\n';
            continue;
        }
        reverse(vacant.begin(), vacant.end());
        dfs(0);
        cout << ans << '\n';
    }
    return 0;
}
