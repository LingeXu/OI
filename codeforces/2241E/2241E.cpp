#include <bits/stdc++.h>
#define N 200020
typedef long long ll;
using namespace std;
int t, n;
ll ans = 0;
int sons_cnt[N];
vector<int> graph[N];  //sons包含自己
vector< pair<int, int> > vertex;
bool is_square(int x) {
    int sq = sqrt(x);
    return sq * sq == x;
} 
void dfs(int u, int fa) {
    for(int v : graph[u]) {
        if(v != fa) {
            dfs(v, u);
            sons_cnt[u] += sons_cnt[v];
        }
    }
}
void solve() {
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        graph[i].clear();
        sons_cnt[i] = 1;
    }
    vertex.clear();
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        vertex.push_back(make_pair(i, val));
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);

    /*for(int i = 1; i <= n; i++) cout << sons_cnt[i] << ' ';
    cout << '\n';*/

    for(auto v : vertex) {
        if(!is_square(v.second))   continue;
        vector<int> cnt;
        int total = 0;
        for(int u : graph[v.first])  {
            if(sons_cnt[u] < sons_cnt[v.first]) {
                cnt.push_back(sons_cnt[u]);
                total += sons_cnt[u];
            }
        }
        cnt.push_back(n - 1 - total);
        int sz = (int)cnt.size();
        if(sz < 2)  continue;
        else if(sz == 2) {
            ans += 1LL * cnt[0] * cnt[1];
            continue;
        }
        else if(sz == 3) {
            ans += (1LL * cnt[0] * cnt[1] + 1LL * cnt[1] * cnt[2] + 1LL * cnt[0] * cnt[2] + 1LL * cnt[0] * cnt[1] * cnt[2]);
            continue;
        }
        else {
            vector<ll> prefix(sz + 1), dp2(sz + 1), dp3(sz + 1);
            prefix[0] = 0;
            for(int i = 1; i <= sz; i++)
                prefix[i] = prefix[i - 1] + 1LL * cnt[i - 1];
            dp2[0] = dp2[1] = dp3[0] = dp3[1] = dp3[2] = 0;
            for(int i = 2; i <= sz; i++) {
                dp2[i] = dp2[i - 1] + cnt[i - 1] * prefix[i - 1];
                dp3[i] = dp3[i - 1] + cnt[i - 1] * dp2[i - 1];
            }
            ans += (dp2[sz] + dp3[sz]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}