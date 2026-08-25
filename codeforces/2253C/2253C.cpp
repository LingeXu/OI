#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, x, y;
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    vector<int> used(n + m + 1, false);
    set< int, greater<int> > s_row, s_col, s;
    for(int i = 0; i < x; i++) 
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < y; i++) 
        cin >> b[i];
    sort(b.begin(), b.end(), cmp);
    int i = 0, j = 0;
    while(((int)s_row.size() < n && i < x) || ((int)s_col.size() < m && j < y)) {
        if((int)s_row.size() < n && i < x) {
            if(!used[a[i]]) {
                s_row.insert(a[i]);
                used[a[i]] = true;
                i++;
            }
            else {
                s_col.erase(a[i]);
                s.insert(a[i]);
                i++;
            }
        }
        if((int)s_col.size() < m && j < y) {
            if(!used[b[j]]) {
                s_col.insert(b[j]);
                used[b[j]] = true;
                j++;
            }
            else {
                s_row.erase(b[j]);
                s.insert(b[j]);
                j++;
            }
        }
    }

    /*for(auto it = s_row.begin(); it != s_row.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    cout << '\n';

    for(auto it = s_col.begin(); it != s_col.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    cout << '\n';

    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    cout << '\n';*/

    int ans = 0;
    auto it1 = s_row.begin(), it2 = s_col.begin(), it3 = s.begin();
    int chosen_cnt = 0;
    while(chosen_cnt < n + m - 1 && (it1 != s_row.end() || it2 != s_col.end() || it3 != s.end())) {
        if(it1 != s_row.end() && it2 != s_col.end() && it3 != s.end()) {
            if(*it1 > max(*it2, *it3)) {
                ans += *it1;
                it1++;
            }
            else if(*it2 > max(*it1, *it3)) {
                ans += *it2;
                it2++;
            }
            else {
                ans += *it3;
                it3++;
            }
        }
        else if(it1 == s_row.end() && it2 != s_col.end() && it3 != s.end()) {
            if(*it2 > *it3) {
                ans += *it2;
                it2++;
            }
            else {
                ans += *it3;
                it3++;
            }
        }
        else if(it1 != s_row.end() && it2 == s_col.end() && it3 != s.end()) {
            if(*it1 > *it3) {
                ans += *it1;
                it1++;
            }
            else {
                ans += *it3;
                it3++;
            }
        }
        else if(it1 != s_row.end() && it2 != s_col.end() && it3 == s.end()) {
            if(*it1 > *it2) {
                ans += *it1;
                it1++;
            }
            else {
                ans += *it2;
                it2++;
            }
        }
        else if(it1 != s_row.end() && it2 == s_col.end() && it3 == s.end()) {
            ans += *it1;
            it1++;
        }
        else if(it1 == s_row.end() && it2 != s_col.end() && it3 == s.end()) {
            ans += *it2;
            it2++;
        }
        else if(it1 == s_row.end() && it2 == s_col.end() && it3 != s.end()) {
            ans += *it3;
            it3++;
        }
        chosen_cnt++;

        //cout << ans << '\n';

    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}