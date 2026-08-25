#include <bits/stdc++.h>
using namespace std;
int t, n, x, s;
string q;
void solve() {
    cin >> n >> x >> s >> q;
    vector<int> remain(x, s), cnt_E(n + 1, 0), cnt_I(n + 1, 0);
    for(int i = 0; i < (int)q.size(); i++) {
        if(q[i] == 'E') {
            cnt_E[i + 1] = cnt_E[i] + 1;
            cnt_I[i + 1] = cnt_I[i];
        }
        else if(q[i] == 'I') {
            cnt_E[i + 1] = cnt_E[i];
            cnt_I[i + 1] = cnt_I[i] + 1;
        }
        else {
            cnt_E[i + 1] = cnt_E[i];
            cnt_I[i + 1] = cnt_I[i];
        }
    }
    int cnt = 0, idx = 0, empty = x;
    auto begin = remain.begin(), end = remain.end();
    for(char c : q) {
        if(c == 'E') {
            auto it = lower_bound(begin, end, 1);
            if(it == end) {
                cout << cnt << '\n';
                return;
            }
            if(*it < s) {
                (*it)--;
                cnt++;
            }
        }
        else if(c == 'I') {
            auto it = lower_bound(begin, end, s);
            if(it != end)  {
                (*it)--;
                cnt++;
                empty--;
            }
        }
        else {
            int not_empty_seat = (x - empty) * s - cnt;
            int remain_E = cnt_E[n] - cnt_E[idx + 1];
            int remain_I = cnt_I[n] - cnt_I[idx + 1];
            if(remain_I >= empty) {
                //cout << "CASE2\n"; 
                auto it = lower_bound(begin, end, 1);
                if(it == end) {
                    cout << cnt << '\n';
                    return;
                }
                if(*it == s)    empty--;
                (*it)--;
                cnt++;
            }
            else {
                auto it = lower_bound(begin, end, s);
                if(it == end) {
                    it--;
                    if(*it == 0) {
                        cout << cnt << '\n';
                        return;
                    }
                }
                else    empty--;
                (*it)--;
                cnt++;
            }
        }
        idx++;
    }
    //cout << remain[0] << ' ' << remain[1] << '\n';
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}