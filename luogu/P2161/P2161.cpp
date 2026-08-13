#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
set< pair<int, int> > s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        if(c == 'A') {
            int l, r;
            cin >> l >> r;
            int del_cnt = 0;
            pair<int, int> line = make_pair(l, r);
            pair<int, int> temp = make_pair(l, l);
            auto it = lower_bound(s.begin(), s.end(), temp);
            if(it != s.begin() && prev(it)->second >= l)
                it = prev(it);
            while(it != s.end() && it->first <= r) {
                it = s.erase(it);
                cnt--;
                del_cnt++;
            }
            s.insert(line);
            cnt++;
            cout << del_cnt << '\n';
        }
        else    cout << cnt << '\n';
    }
    return 0;
}