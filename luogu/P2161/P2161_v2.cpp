#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
struct segment {
    int l, r;
    bool operator<(const segment& x) const{
        return r < x.l;
    }
};
set<segment> s;
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
            segment add = {l, r};
            auto it = s.find(add);
            while(it != s.end()) {
                s.erase(it);
                del_cnt++;
                cnt--;
                it = s.find(add);
            }
            s.insert(add);
            cnt++;
            cout << del_cnt << '\n';
        }
        else    cout << cnt << '\n';
    }
    return 0;
}