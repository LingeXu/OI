#include <bits/stdc++.h>
using namespace std;
int t, n;
bool balance(string s) {
    int cur = 0;
    vector<int> cnt{1, 0, 0};
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(i & 1)   cur++;
            else    cur--;
        }
        cur = (cur + 3) % 3;
        if(cur == 0)    cnt[0]++;
        else if(cur == 1)    cnt[1]++;
        else    cnt[2]++;
    }
    return *max_element(cnt.begin(), cnt.end()) - *min_element(cnt.begin(), cnt.end()) <= 1;
}
void solve() {
    cin >> n;
    if(n == 1) {
        cout << '1' << '\n';
        return;
    }
    if(n == 2) {
        cout << "11" << '\n';
        return;
    }
    if(n == 3) {
        cout << "101" << '\n';
        return;
    }
    if(n == 4) {
        cout << "0101" << '\n';
        return;
    }
    if(n == 5) {
        cout << "10101" << '\n';
        return;
    }
    if(n == 6) {
        cout << "010100" << '\n';
        return;
    }
    int first = n / 3, second = 2 * n / 3;
    for(int i = first; i <= first + 1; i++) {
        for(int j = second; j <= second + 1; j++) {
            for(int putLastOne = 0; putLastOne <= 1; putLastOne++) {
                string s(n, '0');
                s[i - 1] = '1';
                s[j - 1] = '1';
                if(putLastOne == 1)
                    s[n - 1] = '1';
                if(balance(s)) {
                    cout << s << '\n';
                    return;
                }
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}