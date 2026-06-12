#include <bits/stdc++.h>
#define N 200020
#define LOG 20
using namespace std;
int n, m;
int nxt[N * 2], fa[N * 2][LOG], ans[N];
struct edge {
    int l, r, id;
}e[N * 2];

bool cmp_l(edge a, edge b) {
    return a.l < b.l;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r)  r += m;
        e[i] = {l, r, i};
        e[i + n] = {l + m, r + m, i + n};
    }
    sort(e + 1, e + 2 * n + 1, cmp_l);
    int j = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (j < i)  j = i;
        while (j <= 2 * n && e[j].l <= e[i].r) 
            j++;
        nxt[i] = j - 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
        fa[i][0] = nxt[i];
    }
    for (int k = 1; k < LOG; k++) 
        for (int i = 1; i <= 2 * n; i++) 
            fa[i][k] = fa[fa[i][k - 1]][k - 1];
    for (int i = 1; i <= n; i++) {
        int pos = i, cnt = 1;
        int target = e[i].l + m;
        for (int k = LOG - 1; k >= 0; k--) {
            int to = fa[pos][k];
            if (to && e[to].r < target) {
                pos = to;
                cnt += (1 << k);
            }
        }
        ans[e[i].id] = cnt + 1;
    }
    for (int i = 1; i <= n; i++) 
        cout << ans[i] << ' ';
    return 0;
}