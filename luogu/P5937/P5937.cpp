#include <bits/stdc++.h>
#define M 5050
typedef long long ll;
using namespace std;
int n, m;
ll a[M], b[M], to_disperse[2 * M], dispersed[2 * M];
int op[M], fa[4 * M];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry)    fa[rx] = ry;
}
int main() {
    cin >> n >> m;
    int id = 1;
    for(int i = 1; i <= m; i++) {
        string s;
        cin >> a[i] >> b[i] >> s;
        to_disperse[id++] = a[i] - 1;
        to_disperse[id++] = b[i];
        op[i] = (s == "odd" ? 1 : 0);
    }
    sort(to_disperse + 1, to_disperse + id);
    int idx = 0;
    for(int i = 1; i < id; i++)
        if(i == 1 || to_disperse[i] != to_disperse[i - 1])
            dispersed[++idx] = to_disperse[i];
    for(int i = 1; i <= 2 * idx; i++)
        fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int Left = lower_bound(dispersed + 1, dispersed + idx + 1, a[i] - 1) - dispersed;
        int Right = lower_bound(dispersed + 1, dispersed + idx + 1, b[i]) - dispersed;
        if(op[i] == 0) {
            if(find(Left) == find(Right + idx)) {
                cout << i - 1;
                return 0;
            }
            unite(Left, Right);
            unite(Left + idx, Right + idx);
        }
        else {
            if(find(Left) == find(Right)) {
                cout << i - 1;
                return 0;
            }
            unite(Left + idx, Right);
            unite(Left, Right +idx);
        }
    }
    cout << m;
    return 0;
}