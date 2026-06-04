#include <bits/stdc++.h>
#define N 200020
#define M 200020
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
int n, m;
ll s;
struct stone {
    int w, v;
    ll a_sum, b_sum;
}st[N];
struct pos {
    int l, r;
}p[M];
ll check(int W) {
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        st[i].a_sum = st[i - 1].a_sum + (st[i].w >= W);
        st[i].b_sum = st[i - 1].b_sum + (st[i].w >= W) * st[i].v;
    }
    for(int i = 1; i <= m; i++)
        ans += (st[p[i].r].a_sum - st[p[i].l - 1].a_sum) * (st[p[i].r].b_sum - st[p[i].l - 1].b_sum);
    return ans;
}
int main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++)
        cin >> st[i].w >> st[i].v;
    for(int i = 1; i <= m; i++) 
        cin >> p[i].l >> p[i].r;
    ll ans = 1e18;
    int Left = 0, Right = 1e6;
    while(Left <= Right) {
        int mid = Left + (Right - Left) / 2;
        ll now = check(mid);
        if(now > s) {
            Left = mid + 1;
            ans = 1LL * min(ans, now - s);
        }
        else {
            Right = mid - 1;
            ans = 1LL * min(ans, s - now);
        }
    }
    cout << ans;
    return 0;
}