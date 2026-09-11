#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    string s;
    cin >> s;
    if(s == "111" || s == "000") {
        cout << -1 << '\n';
        return;
    }
    int sum_0 = 0, sum_1 = 0;
    for(int i = 0; i < n; ) {
        int cnt = 0;
        int j = i + 1;
        while(s[j] == s[i]) {
            cnt++;
            j++;
        }
        if(s[i] == '0') {
            sum_0 += cnt;
        }
        else {
            sum_1 += cnt;
        }
        i = j;
    }
    if(abs(sum_0 - sum_1) <= 1) {
        cout << sum_0 + sum_1 << '\n';
        return;
    }
    else if(abs(sum_0 - sum_1) > 3){
        cout << -1 << '\n';
        return;
    }
    else {
        if(sum_0 - sum_1 == 2 && (s[0] == '1' || s[n - 1] == '1')) {
            cout << sum_0 + sum_1 + 1 << '\n';
            return;
        }
        if(sum_0 - sum_1 == 3 && (s[0] == '1' && s[n - 1] == '1')) {
            cout << sum_0 + sum_1 + 2 << '\n';
            return;
        }
        if(sum_1 - sum_0 == 2 && (s[0] == '0' || s[n - 1] == '0')) {
            cout << sum_0 + sum_1 + 1 << '\n';
            return;
        }
        if(sum_1 - sum_0 == 3 && (s[0] == '0' && s[n - 1] == '0')) {
            cout << sum_0 + sum_1 + 2 << '\n';
            return;
        }
    }  
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}