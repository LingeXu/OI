#include <bits/stdc++.h>
#define N 10010
#define M 5050
#define W 10010
using namespace std;
int n, m, w, ans = 0;
int fa[N], dp[W];
struct cloud {
    int cost, val;
}c[N], updated_c[N];
struct inf {
    int father, id, idx;
}node[N];
bool cmp(inf a, inf b) {
    return a.father < b.father || (a.father == b.father && a.id < b.id);
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) 
        fa[max(rx, ry)] = min(rx, ry);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++) 
        cin >> c[i].cost >> c[i].val;
    for(int i = 0; i < n; i++)
        fa[i] = i;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u - 1, v - 1);
    }
    for(int i = 0; i < n; i++) 
        node[i] = {find(i), i};
    sort(node, node + n, cmp);
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || node[i].father != node[i - 1].father) 
            node[i].idx = start++;
        else 
            node[i].idx = node[i - 1].idx;
    }
    for(int i = 0; i < n; i++) {
        updated_c[node[i].idx].cost += c[node[i].id].cost;
        updated_c[node[i].idx].val += c[node[i].id].val;
    }

    /*for(int i = 1; i < start; i++)
        for(int j = 0; j <= w; j++)
            if(j - updated_c[i].cost >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - updated_c[i].cost] + updated_c[i].val);*/

    for(int i = 0; i < start; i++)
        for(int j = w; j >= updated_c[i].cost; j--)
            dp[j] = max(dp[j], dp[j - updated_c[i].cost] + updated_c[i].val);
    cout << dp[w];
    return 0;
}