#include <bits/stdc++.h>
#define A 1010
#define B 510
using namespace std;
int a, b, ans;
struct edge {
    int from, to, val;
}e[B * B];
bool cmp(edge x, edge y) {
    return x.val < y.val;
}
int fa[B];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y, int v) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        ans += v;
        fa[rx] = ry;
    }
}
int main() {
    cin >> a >> b;
    ans = a;
    int id = 0;
    for(int i = 1; i <= b; i++) {
        for(int j = 1; j <= b; j++) {
            int val;
            cin >> val;
            e[id].from = i;
            e[id].to = j;
            if(val == 0)    e[id].val = a;
            else    e[id].val = min(a, val);
            id++;
        }
    }
    sort(e, e + b * b, cmp);
    for(int i = 1; i <= b; i++) fa[i] = i;
    for(int i = 0; i < b * b; i++) {
        int f = e[i].from;
        int t = e[i].to;
        int v = e[i].val;
        unite(f, t, v);
    }
    cout << ans;
    return 0;
}