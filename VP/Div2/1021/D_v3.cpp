// CF Round 1021 (Div.2) D - Baggage Claim (2098D)
// 已知简单路径 p1..p{2k+1} 的奇数项(共 k+1 个互不相同的格子)，
// 求能补全出多少条路径（相邻格共边、所有格互不重复），模 1e9+7。
//
// 思路：
// 1. 相邻给定点曼哈顿距离必须恰为 2，否则 0。
// 2. 每对相邻给定点 (i, i+1) 之间要插入 1 个格子：
//    - 同行/同列差 2  -> 插入格唯一（中点）       -> 看作该格上的「自环」
//    - 斜对角差 (1,1) -> 两个拐角格二选一         -> 看作两格之间的一条「边」
// 3. 插入格互不相同 <=> 每条边选一个端点、每个端点至多被一条边选中。
//    （给定点两两同奇偶、插入格与其相邻所以反奇偶，插入格不可能撞给定点）
// 4. 对每个连通块分类计数，答案相乘：
//    - 点数 V < 边数 E : 0（鸽笼原理）
//    - V == E + 1（树）: V（未选中的点可任意指定，其余配对被强制唯一确定）
//    - V == E（基环）  : 环外树枝被强制；剩一个环：
//         自环 -> 1 种；真环 -> 2 种（顺/逆时针）
#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int t, n, m, k;

struct DSU {
    vector<int> f;
    vector<int> edge_cnt, vtx_cnt;
    vector<char> self;          // 连通块内是否含自环
    DSU(int sz) : f(sz), edge_cnt(sz, 0), vtx_cnt(sz, 0), self(sz, 0) {
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    // 加入一条边 u-v（u == v 表示自环）
    void add_edge(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) {
            edge_cnt[ru]++;
            if (u == v) self[ru] = 1;
        } else {
            f[rv] = ru;
            edge_cnt[ru] += edge_cnt[rv] + 1;
            self[ru] |= self[rv];
        }
    }
};

inline int id(int x, int y) { return (x - 1) * m + (y - 1); }

void solve() {
    cin >> n >> m >> k;
    vector<pair<int, int> > P(k + 2);
    for (int i = 1; i <= k + 1; i++)
        cin >> P[i].first >> P[i].second;
    DSU d(n * m);
    vector<int> cells;                      // 所有候选插入格（允许重复）
    bool bad = false;
    for (int i = 1; i <= k; i++) {
        int dx = P[i + 1].first - P[i].first;
        int dy = P[i + 1].second - P[i].second;
        if (abs(dx) + abs(dy) != 2) { bad = true; continue; }
        int u, v;
        if (dx == 0)                        // 同列 |dy| = 2：唯一插入格 -> 自环
            u = v = id(P[i].first, P[i].second + dy / 2);
        else if (dy == 0)                   // 同行 |dx| = 2：唯一插入格 -> 自环
            u = v = id(P[i].first + dx / 2, P[i].second);
        else {                              // 斜对角：两个拐角二选一 -> 一条边
            u = id(P[i].first + dx, P[i].second);
            v = id(P[i].first, P[i].second + dy);
        }
        d.add_edge(u, v);
        cells.push_back(u);
        if (u != v) cells.push_back(v);
    }
    if (bad) { cout << 0 << '\n'; return; }
    vector<char> seen(n * m, 0);
    vector<int> roots;
    for (size_t i = 0; i < cells.size(); i++) {   // 每个候选格只计一次
        int c = cells[i];
        if (seen[c]) continue;
        seen[c] = 1;
        int r = d.find(c);
        d.vtx_cnt[r]++;
        roots.push_back(r);
    }
    long long ans = 1;
    vector<char> root_seen(n * m, 0);
    for (size_t i = 0; i < roots.size(); i++) {
        int r = roots[i];
        if (root_seen[r]) continue;
        root_seen[r] = 1;
        int V = d.vtx_cnt[r], E = d.edge_cnt[r];
        if (E > V)          ans = 0;                        // 鸽笼原理
        else if (E == V)    ans = ans * (d.self[r] ? 1 : 2) % MOD;   // 环
        else                ans = ans * V % MOD;            // 树 (E == V-1)
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
