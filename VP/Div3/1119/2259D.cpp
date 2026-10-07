#include <bits/stdc++.h>
using namespace std;
struct inf {
    int val, id;
    char c = '?';
    bool operator<(const inf& other) const {
        return val < other.val;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<inf> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    string ans(n, '?');
    int cur = 0, cmp = 0;
    for(; ; cur++) {
        auto it1 = lower_bound(a.begin(), a.end(), inf{cur, -1, '?'}), it2 = lower_bound(a.begin(), a.end(), inf{cur + 1, -1, '?'});
        if(it1 == a.end())    break;
        int cnt = it2 - it1;
        if(cnt >= 3) {
            cmp++;
            it1->c = 'A';
            (next(it1))->c = 'B';
            (next(next(it1)))->c = 'C';
            for(auto it = next(next(next(it1))); it != it2; it++)
                it->c = 'A';
        }
        else    break;
    }
    auto it1 = lower_bound(a.begin(), a.end(), inf{cur, -1, '?'}), it2 = lower_bound(a.begin(), a.end(), inf{cur + 1, -1, '?'});
    int cnt = it2 - it1;
    if(cnt == 0) {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
            ans[a[i].id] = a[i].c;
        for(char c : ans) {
            if(c == '?')
                cout << 'A';
            else    cout << c;
        }
        cout << '\n';
        return;
    }
    else if(cnt == 1) {
        if(cmp == 0) {
            cout << "NO\n";
            return;
        }
        else {
            cout << "YES\n";
            it1->c = 'C';
            for(int i = 0; i < n; i++)
                ans[a[i].id] = a[i].c;
            for(char c : ans) {
                if(c == '?')
                    cout << 'A';
                else    cout << c;
            }
            cout << '\n';
            return;
        }
    }
    else if(cnt == 2) {
        cout << "YES\n";
        it1->c = 'A';
        next(it1)->c = 'B';
        for(int i = 0; i < n; i++)
            ans[a[i].id] = a[i].c;
        for(char c : ans) {
            if(c == '?')
                cout << 'C';
            else    cout << c;
        }
        cout << '\n';
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}