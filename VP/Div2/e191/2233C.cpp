#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
string s;
void solve() {
    cin >> n >> k >> s;
    string mask(n, '0');
    vector<int> pref_cnt(n, 0), suff_cnt(n, 0);
    for(int i = 0; i < n; i++) {
        if(i == 0)  pref_cnt[i] = 0;
        else    pref_cnt[i] =  pref_cnt[i - 1] + (s[i - 1] == '(' ? 1 : 0);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1)  suff_cnt[i] = 0;
        else    suff_cnt[i] = suff_cnt[i + 1] + (s[i + 1] == ')' ? 1 : 0);
    }
    int pairs = LLONG_MAX;
    int pos = -1;
    for(int i = 0; i < n; i++) {
        if(pref_cnt[i] + suff_cnt[i] < pairs) {
            pairs = pref_cnt[i] + suff_cnt[i];
            pos = i;
        }
    }

    //cout << "pos = " << pos << ", pairs = " << pairs << '\n';

    int op = min(k, pairs);
    for(int i = 0; i < n; i++) {
        if(op <= 0) 
            break;
        if(i < pos && s[i] == '(') {
            mask[i] = '1';
            op--;
        }
        else if(i > pos && s[i] == ')') {
            mask[i] = '1';
            op--; 
        }
    }
    cout << mask << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}