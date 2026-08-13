#include <bits/stdc++.h>
#define N 500050
typedef long long ll;
using namespace std;
int n;
ll cnt = 0;
int a[N];
ll tree[N];
map<int, int> mp;
int lowbit(int x) {
    return x & (-x);
}
void add(int pos, int delta) {
    for(int i = pos; i <= n; i += lowbit(i))   tree[i] += 1LL * delta;
}
ll query(int pos) {
    ll res = 0;
    for(int i = pos; i > 0; i -= lowbit(i))    res += tree[i];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i]; 
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    /*for(int i = 0; i < (int)b.size(); i++)
        cout << b[i] << ' ';*/
    
    for(int i = 0; i < (int)b.size(); i++)
        mp[b[i]] = i + 1;
    for(int i = n - 1; i >= 0; i--) {
        cnt += query(mp[a[i]] - 1);
        add(mp[a[i]], 1);
    }
    cout << cnt;
    return 0;
}