#include <bits/stdc++.h>
#define N 1010
using namespace std;
int t, n, m, k;
int a[N][N];
bool vis[N][N];
struct op {
    int r, x, y;
};
vector< tuple<int, int, op> > graph[N][N];
vector<op> ans;
void add_edge(int ux, int uy, int vx, int vy, op w) {
    graph[ux][uy].emplace_back(vx, vy, w);
    graph[vx][vy].emplace_back(ux, uy, w);
}
void dfs(int ux, int uy) {
    vis[ux][uy] = true;
    for(auto [vx, vy, w] : graph[ux][uy]) {
        if(!vis[vx][vy]) {
            dfs(vx, vy);
            if(a[vx][vy] == 1) {
                a[ux][uy] ^= 1;
                ans.push_back(w);
            }
        }
    }
}
void solve() {
    memset(vis, 0, sizeof(vis));
    ans.clear();
    cin >> n >> m >> k;
    for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= m + 1; j++)
            graph[i][j].clear();
    
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
            a[i][j] = s[j - 1] - '0';
    }
    for(int i = 1; i <= m + 1; i++)
        a[n + 1][i] = 0;
    for(int i = 1; i <= n + 1; i++)
        a[i][m + 1] = 0;
    for(int i = n + 1; i >= 1; i--)
        for(int j = m + 1; j >= 1; j--)
            a[i][j] ^= a[i - 1][j] ^ a[i][j - 1] ^ a[i - 1][j - 1];
    for(int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        for(int a = 1; a + x <= n + 1; a++) {
            for(int b = 1; a == 1 ? b + y <= m + 1 : b == 1; b++) {
                if(a == 1 && b == 1) 
                    add_edge(1, 1, a + x, b + y, {i, a, b});
                else if(a == 1 && b != 1)   add_edge(a + x, b, a + x, b + y, {i, a, b});
                else    add_edge(a, b + y, a + x, b + y, {i, a, b});
            }
        }
    }
    for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= m + 1; j++)
            if(!vis[i][j])
                dfs(i, j);
    cout << (int)ans.size() << '\n';
    for(auto [r, x, y] : ans)
        cout << r << ' ' << x << ' ' << y << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}