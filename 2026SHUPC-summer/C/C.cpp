#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int q, l, r;
ll length = 0;
set< pair<int, int> > s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while(q--) {
        cin >> l >> r;
        if(s.empty()) {
            s.insert(make_pair(l, r));
            length = r - l;
            cout << 1 << ' ' << length << '\n';
            continue;
        }
        int new_l = l, new_r = r;
        auto it = s.lower_bound(make_pair(l, l));
        if(it != s.begin() && prev(it)->second >= l) {
            it = prev(it);
            new_l = it->first;
        }
        while(it != s.end() && it->first <= r) {
            length -= 1LL * (it->second - it->first);
            if(it->second >= r)
                new_r = it->second;
            it = s.erase(it); 
        }
        s.insert(make_pair(new_l, new_r));
        length += 1LL * (new_r - new_l);
        cout << s.size() << ' ' << length << '\n';
    }
    return 0;
}