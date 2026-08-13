#include <bits/stdc++.h>
#define MAX_BITS 32
typedef long long ll;
using namespace std;
int t, n, q;
bool in_order;
void init(int sz, vector<int>& x, map<int, int>& y_max, map<int, int>& y_min) {
    deque< pair<int, int> > s_up, s_down;
    for(int i = 0; i < (int)x.size(); i++) {
        while(!s_up.empty() && x[i] < s_up.back().second) s_up.pop_back();
        s_up.push_back({i, x[i]});
        while(s_up.front().first < i - sz + 1)   s_up.pop_front();
        y_min[i] = s_up.front().second;
    }
    for(int i = 0; i < (int)x.size(); i++) {
        while(!s_down.empty() && x[i] > s_down.back().second) s_down.pop_back();
        s_down.push_back({i, x[i]});
        while(s_down.front().first < i - sz + 1)   s_down.pop_front();
        y_max[i] = s_down.front().second;
    }
}
void solve() {
    in_order = true;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0 && a[i] < a[i - 1])   in_order = false;
    }
    if(in_order) {
        cout << 0 << '\n';
        return;
    }
    else {
        for(int i = 0; i < MAX_BITS; i++)  {
            int sz = (1 << i) + 1;
            int group_cnt = (n + sz - 1) / sz;
            vector<int> b(group_cnt * sz);
            for(int j = 0; j < group_cnt * sz; j++) {
                if(j < n)   b[j] = a[j];
                else    b[j] = 0x3f3f3f3f;
            }
            int min_val_of_this_group , max_val_of_this_group = -1;
            bool ok = true;
            map<int, int> mp_max, mp_min;
            init(sz, b, mp_max, mp_min);
            for(int j = 1; j <= group_cnt; j++) {
                int start_idx = sz * (j - 1);
                int end_idx = start_idx + sz - 1;
                min_val_of_this_group = mp_min[end_idx];
                if(min_val_of_this_group < max_val_of_this_group) {
                    ok = false;
                    break;
                }
                max_val_of_this_group = mp_max[end_idx];
            }
            if(ok) {
                cout << sz - 1 << '\n';
                return;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}