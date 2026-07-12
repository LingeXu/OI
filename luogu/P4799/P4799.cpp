#include <bits/stdc++.h>
#define N 41
using namespace std;
int n, m, ans = 0;
int a[N];
vector<int> c;
void dfs(int pos, int cost) {
    if(pos >= c.size() || cost > m)
        return;
    if(cost + c[pos] > m) 
        ans++;
    for(int i = pos + 1; i < c.size(); i++) {
        dfs(i, cost);
        dfs(i, cost + c[pos]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int idx = 1;
    while(a[idx] > m)
        idx++;
    while(idx <= n)
        c.push_back(a[idx++]);
    cout << '\n';
    dfs(0, 0);
    cout << ans;
    return 0;
}