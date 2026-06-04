#include<iostream>
#include<cstring>
using namespace std;

const int N = 505;
const int E = 50005;

struct edge {
    int to, next;
} ed[E];

int head[N];
int occ[N];
bool vis[N];

bool dfs(int start) {
    for (int i = head[start]; i; i = ed[i].next) {
        int v = ed[i].to;
        if (vis[v]) continue;
        vis[v] = true;
        if (!occ[v] || dfs(occ[v])) {
            occ[v] = start;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, e;
    scanf("%d%d%d", &n, &m, &e);

    for (int i = 1; i <= e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ed[i].to = b;
        ed[i].next = head[a];
        head[a] = i;   
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}