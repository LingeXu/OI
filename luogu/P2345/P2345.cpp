#include <bits/stdc++.h>
#define N 20020
typedef long long ll;
using namespace std;
int n;
ll ans = 0;
struct Cow {
    int v, x;
}a[N];
bool cmp(Cow x, Cow y) {
    return x.v < y.v;
}
struct BIT {
    int n;
    vector<ll> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int idx, ll val) {
        for(; idx <= n; idx += idx & -idx)
            t[idx] += val;
    }
    ll sum(int idx) {
        ll res = 0;
        for(; idx > 0; idx -= idx & -idx)
            res += t[idx];
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i].v >> a[i].x;
    sort(a + 1, a + 1 + n, cmp);
    vector<int> xs;
    for(int i = 1; i <= n; i++)
        xs.push_back(a[i].x);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int m = xs.size();
    BIT cntBIT(m), sumBIT(m);

    /*ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(xs.begin(), xs.end(), a[i].x) - xs.begin() + 1;
        ll cntL = cntBIT.sum(pos - 1);
        ll sumL = sumBIT.sum(pos - 1);
        ll cntR = cntBIT.sum(m) - cntBIT.sum(pos);
        ll sumR = sumBIT.sum(m) - sumBIT.sum(pos);
        ll left = (ll)a[i].x * cntL - sumL;
        ll right = sumR - (ll)a[i].x * cntR;
        ans += (ll)a[i].v * (left + right);
        cntBIT.add(pos, 1);
        sumBIT.add(pos, a[i].x);
    }*/

    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(xs.begin(), xs.end(), a[i].x) - xs.begin() + 1;
        ll cntL = cntBIT.sum(pos - 1);
        ll sumL = sumBIT.sum(pos - 1);
        ll cntR = cntBIT.sum(m) - cntBIT.sum(pos);
        ll sumR = sumBIT.sum(m) - sumBIT.sum(pos);
        ll Left = 1LL * a[i].x * cntL - sumL;
        ll Right = sumR - 1LL * a[i].x * cntR;
        ans += 1LL * a[i].v * (Left + Right);
        cntBIT.add(pos, 1);
        sumBIT.add(pos, a[i].x);
    }
    cout << ans << "\n";
    return 0;
}