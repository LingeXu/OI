#include <bits/stdc++.h>
#define N 1010
typedef long long ll;
using namespace std;
int n, c, idx = 0;
ll ans = 0;
int w[N], v[N];
ll prefix[N];
void dfs(int pos, ll sum) {
    if(sum > c || pos > idx)
        return;
    if(sum == c) {
        ans = c;
        return;
    }
    if(pos < idx && sum + prefix[idx - pos - 1] <= c) {
        ans = max(ans, sum + prefix[idx - pos - 1]);
        return;
    }
    ans = max(ans, sum);
    for(int i = pos; i < idx; i++)
        dfs(i + 1, sum + v[i]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        if(w[i] == c) {
            cout << c;
            return 0;
        }
        else if(w[i] > c)   continue;
        v[idx++] = w[i];
    }
    if(idx == 0) {
        cout << 0;
        return 0;
    }
    prefix[0] = v[0];
    for(int i = 1; i < idx; i++) 
        prefix[i] = prefix[i - 1] + v[i];
    sort(v, v + idx, greater<int>());
    dfs(0, 0);
    cout << ans;
    return 0;
}