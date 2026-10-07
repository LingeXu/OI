#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    string s(n, '?');
    vector<int> diff(n + 1), presum(n + 1);
    for(int i = 0; i < n; i++) {
        if(a[i] <= 0)   continue;
        int l = max(0, i - a[i] + 1), r = min(n - 1, i + a[i] - 1);
        diff[l]++;
        diff[r + 1]--;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0)  presum[i] = diff[i];
        else    presum[i] = presum[i - 1] + diff[i];
        if(presum[i] != 0)  s[i] = '0';
    }

    //cout << "Test:" << '\n';
    //cout << s << '\n';

    for(int i = 0; i < n; i++) {
        if(a[i] == -1)  continue;
        int l = i - a[i], r = i + a[i];
        if(l < 0 && r > n - 1) {
            cout << -1 << '\n';
            return;
        }
        if(l < 0) {
            if(s[r] == '0') {
                cout << -1 << '\n';
                return;
            }
            else    s[r] = '1';
            continue;
        }
        if(r > n - 1) {
            if(s[l] == '0') {
                cout << -1 << '\n';
                return;
            }
            else    s[l] = '1';
            continue;
        }
        if(s[l] == '0' && s[r] == '0') {
            cout << -1 << '\n';
            return;
        }
        if(s[l] == '0') {
            s[r] = '1';
            continue;
        }
        s[l] = '1';
    }
    for(char &c : s) 
        if(c == '?')
            c = '1';
    bool ok = false;
    for(char c : s) {
        if(c == '1') {
            ok = true;
            break;
        }
    }
    if(!ok) {
        cout << -1 << '\n';
        return;
    }
    else    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}