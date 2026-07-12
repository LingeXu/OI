#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, m, now = 0;
double ans = 0;
int fa[N];
struct location {
    int x, y;
} node[N];
struct edge {
    int id1, id2;
    double val;
};
vector<edge> e;
double GetDist(int i, int j) {
    double dx = node[i].x - node[j].x;
    double dy = node[i].y - node[j].y;
    return sqrt(dx * dx + dy * dy);
}
bool cmp(edge x, edge y) {
    return x.val - y.val < 1e-10;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y, int& remain, double& ans, bool add) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        fa[rx] = ry;
        remain--;
        if(add == true)
            ans += GetDist(x, y);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> node[i].x >> node[i].y;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double val = GetDist(i, j);
            e.push_back({i, j, val});
        }
    }
    for(int i = 0; i < n; i++)
        fa[i] = i;
    int remain = n - 1;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v)   swap(u, v);
        unite(u - 1, v - 1, remain, ans, false);
    }
    sort(e.begin(), e.end(), cmp);
    int now = 0;
    while(remain > 0 && now < e.size()) {
        unite(e[now].id1, e[now].id2, remain, ans, true);
        now++;
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}