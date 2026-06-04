#include <bits/stdc++.h>
#define N 50050
#define LOG 17
using namespace std;
int n, q;
int h[N];
int fa_max[N][LOG], fa_min[N][LOG];
void init() {
    for(int i = 1; i <= n; i++) {
        fa_max[i][0] = h[i];
        fa_min[i][0] = h[i];
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n - (1 << i) + 1; j++) {
            fa_max[j][i] = max(fa_max[j][i - 1], fa_max[j + (1 << (i - 1))][i - 1]);
            fa_min[j][i] = min(fa_min[j][i - 1], fa_min[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    init();
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int Length = r - l + 1;
        int max_height = 0, min_height = 1e6;
        int x = 0;
        int now = 1;
        while(now <= Length) {
            now *= 2;
            x++;
        }
        x--;
        max_height = max(fa_max[l][x], fa_max[r - (1 << x) + 1][x]);
        min_height = min(fa_min[l][x], fa_min[r - (1 << x) + 1][x]);
        cout << max_height - min_height << '\n';
    }
    return 0;
}