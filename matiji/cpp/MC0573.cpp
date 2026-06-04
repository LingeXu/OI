#include <bits/stdc++.h>
#define N 1000010
#define M 1000010
typedef long long ll;
using namespace std;
int n, m, L;
ll ans = LLONG_MAX;
int u[M], v[M], b[M], k[M], fa[N];
struct edge {
    int from, to, k, b, val;
};
vector<edge> graph;
bool cmp(edge a, edge b) {
    return a.val > b.val;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx= find(x), ry = find(y);
    if(rx != ry)    fa[rx] = ry;
}
ll check(int x) {
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    ll sum = 0;
    for(edge& e : graph) 
        e.val = e.k * x + e.b;
    sort(graph.begin(), graph.end(), cmp);
    for(edge e : graph) {
        if(find(e.from) != find(e.to)) {
            unite(e.from, e.to);
            sum += 1LL * e.val;
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> L;
    for(int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> b[i] >> k[i];
        edge e1;
        e1.from = u[i];
        e1.to = v[i];
        e1.k = k[i];
        e1.b = b[i];
        graph.push_back(e1);   
    }
    ll Left = 0, Right = L;
    while(Left <= Right) {
        ll Mid = Left + (Right - Left) / 2;
        ll w1 = check(Mid), w2 = (Mid + 1 <= L ) ? check(Mid + 1) : LLONG_MAX;
        if(w1 > w2) {
            ans = min(ans, w2);
            Left = Mid + 1;
        }
        else {
            ans = min(ans, w1);
            Right = Mid - 1;
        }
    }
    cout << ans;
    return 0;
}