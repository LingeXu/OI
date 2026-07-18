#include <bits/stdc++.h>
#define N 5050
using namespace std;
int n;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    vector<int> d, d_idx, pre(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        int p = it - d.begin();
        if(p - 1 >= 0)
            pre[i] = d_idx[p - 1];
        if(it == d.end()) {
            d.push_back(a[i]);
            d_idx.push_back(i);
        }
        else {
            *it = a[i];
            d_idx[p] = i;
        }
    }
    int maxlen = d.size();
    vector<int> lis;
    int now = d_idx.back();
    while(now != -1) {
        lis.push_back(a[now]);
        now = pre[now];
    }
    reverse(lis.begin(), lis.end());
    cout << maxlen << '\n';
    for(auto it = lis.begin(); it != lis.end(); it++)
        cout << *it << ' ';
    return 0;
}