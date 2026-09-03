#include <bits/stdc++.h>
using namespace std;
int n, q;
struct inf {
    int l, r, val;
};
vector<inf> a_, b_;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i]; 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto it = a.begin();
    while(it != a.end()) {
        int aim = *it;
        auto it1 = lower_bound(a.begin(), a.end(), aim), it2 = upper_bound(a.begin(), a.end(), aim);
        a_.push_back({it1 - a.begin() + 1, it2 - a.begin(), *it});
        it = it2;
    }

    auto it_ = a.begin();
    while(it_ != b.end()) {
        int aim = *it_;
        auto it1 = lower_bound(b.begin(), b.end(), aim), it2 = upper_bound(b.begin(), b.end(), aim);
        b_.push_back({it1 - b.begin() + 1, it2 - b.begin(), *it_});
        it_ = it2;
    }

    for(int i = 0; i < (int)a_.size(); i++)
        cout << a_[i].l << ' ' << a_[i].r << ' ' << a_[i].val << '\n';

    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}