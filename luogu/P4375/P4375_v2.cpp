#include <bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int n;
int rk[N];
bool vis[N];
struct inf {
    ll val;
    int id;
}a[N];
bool cmp(inf x, inf y) {
    return x.val < y.val;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++)
        rk[a[i].id] = i;
    int ans = 1, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(rk[i] > i)   cnt++;
        if(vis[i])  cnt--;
        vis[rk[i]] = true;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}