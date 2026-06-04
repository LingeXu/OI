#include <bits/stdc++.h>
#define N 25
using namespace std;
int n;
int val[N], dp[N], nx[N];
bool vis[N];
bool has_edge[N][N];

vector<int> route;
int dfs(int x){
    if(vis[x])  return dp[x];
    vis[x] = true;
    for(int i = x + 1; i <= n; i++) {
        if(has_edge[x][i]) {
            if(dfs(i) + val[x] > dp[x]) {
                nx[x] = i;
                dp[x] = max(dp[x], dfs(i) + val[x]);
            }
        }
    }
    return dp[x];
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        dp[i] = val[i];
    }
    memset(has_edge, 0, sizeof(has_edge));
    for(int i = 1; i <= n - 1; i++)
        for(int j = i + 1; j <= n; j++)
            cin >> has_edge[i][j];
    memset(vis, 0, sizeof(vis));
    int ans = 0, start;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int now = dfs(i);
            if(now > ans) {
                ans = now;
                start = i;
                route.push_back(i);
            }
        }
    }
    int now = start;
    while(1) {
        cout << now << ' ';
        now = nx[now];
        if(now == 0)    break;
    }
    cout << '\n';
    cout << ans;
    return 0;
}