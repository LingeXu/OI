#include <bits/stdc++.h>
#define N 300030
#define M 300030
typedef long long ll;
using namespace std;
int n, m;
int tree[N];
ll ans = 0;
struct inf {
    int val, pos;
} a[N];
struct question {
    int l, r, power;
} q[M];
struct good_pair {
    int l, r;
};
vector<good_pair> gp;
inline bool cmp1(inf a, inf b) {
    return a.val < b.val;
}
inline bool cmp2(good_pair a, good_pair b) {
    return a.r < b.r;
}
inline bool cmp3(question a, question b) {
    return a.r < b.r;
}
inline int lowbit(int x) {
    return x & (-x);
}
void add(int pos, int delta) {
    for(int i = pos; i <= n; i += lowbit(i))
        tree[i] += delta;
}
int query(int pos) {
    ll res = 0;
    for(int i = pos; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].pos = i + 1;
    }
    sort(a, a + n, cmp1);
    for(int i = 0; i < n; i++) {
        if(i == 0)
            gp.push_back({min(a[0].pos, a[1].pos), max(a[0].pos, a[1].pos)});
        else if(i == n - 1)
            gp.push_back({min(a[n - 1].pos, a[n - 2].pos),max(a[n - 1].pos, a[n - 2].pos)});
        else {
            if(a[i].val - a[i - 1].val <= a[i + 1].val - a[i].val) 
                gp.push_back({min(a[i].pos, a[i - 1].pos), max(a[i].pos, a[i - 1].pos)});
            if(a[i].val - a[i - 1].val >= a[i + 1].val - a[i].val)
                gp.push_back({min(a[i].pos, a[i + 1].pos), max(a[i].pos, a[i + 1].pos)});
        }
    }
    sort(gp.begin(), gp.end(), cmp2);
    for(int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].power = i + 1;
    }
    sort(q, q + m, cmp3);

    /*for(int i = 0; i < (int)gp.size(); i++)
        cout << gp[i].l << ' ' << gp[i].r << '\n';

    for(int i = 0; i < m; i++)
        cout << q[i].l << ' ' << q[i].r << ' ' << q[i].power << '\n';*/

    for(int i = 0, j = 0; i < m; i++) {
        while(j < (int)gp.size() && gp[j].r <= q[i].r) {
            add(gp[j].l, 1);
            j++;
        }
        ans += 1LL * q[i].power * (query(q[i].r) - query(q[i]. l - 1));
    }
    cout << ans;
    return 0;
}