#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, k, ans2 = 0;
ll ans1 = 0;
priority_queue< pair<ll, int> , vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
void build() {
    int precess_cnt = n % (k - 1);
    if(precess_cnt == 0)    precess_cnt = k - 1;
    if(precess_cnt != 1) {
        ll add = 0;
        for(int i = 1; i <= precess_cnt; i++) {
            auto x = pq.top();
            add += x.first;
            pq.pop();
        }
        pq.push({add, 1});
        ans1 += add;
        ans2 = 1;
    }
    while((int)pq.size() >= k) {
        ll add = 0;
        int height = -1;
        for(int i = 1; i <= k; i++) {
            auto x = pq.top();
            add += x.first;
            height = max(height, x.second);
            pq.pop();
        }
        pq.push({add, height + 1});
        ans1 += add;
        ans2 = max(ans2, height + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        ll w;
        cin >> w;
        pq.push({w, 0});
    }
    build();
    cout << ans1 << '\n';
    cout << ans2;
    return 0;
}