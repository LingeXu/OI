#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005
int n;
int tree[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int idx, int delta) {
    for(int i = idx; i <= n; i += lowbit(i))
        tree[i] += delta;
}
int pref_sum(int idx) {
    int res = 0;
    for(int i = idx; i > 0; i -= lowbit(i))
        res += tree[i];
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int len_moves = n - 1;
    for(int i = n - 1; i >= 1; i--) {
        if(pos[i] < pos[i + 1])
            len_moves--;
        else    break;
    }
    cout << len_moves << ' ' << len_moves << '\n';
    int start = len_moves;
    for(int i = start; i >= 1; i--) {
        cout << pos[i] + start - i - pref_sum(pos[i]) << ' ' << 1 << '\n';
        add(pos[i], 1);
    }
    return 0;
}