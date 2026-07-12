#include <bits/stdc++.h>
#define N 41
typedef long long ll;
using namespace std;
int n;
ll m, ans = 0;
ll c[N];
vector<ll> cost, sum1, sum2;
void dfs(int l, int r, ll sum, vector<ll>& arr) {
    if(sum > m)
        return;
    if(l > r) {
        arr.push_back(sum);
        return;
    }
    dfs(l + 1, r, sum + cost[l], arr);
    dfs(l + 1, r, sum, arr);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> c[i];
    sort(c + 1, c + n + 1, greater<ll>());
    int idx = 1;
    while(idx <= n && c[idx] > m) 
        idx++;
    for(; idx <= n; idx++)
        cost.push_back(c[idx]);
    int sz = cost.size();
    int mid = sz / 2;
    dfs(0, mid - 1, 0, sum1);
    dfs(mid, sz - 1, 0, sum2);
    sort(sum2.begin(), sum2.end());
    for(int i = 0; i < sum1.size(); i++) {
        int j = upper_bound(sum2.begin(), sum2.end(), m - sum1[i]) - sum2.begin();
        ans += j;
    }
    cout << ans;
    return 0;
}