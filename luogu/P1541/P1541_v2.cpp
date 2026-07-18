#include <bits/stdc++.h>
#define N 355
#define M 130
using namespace std;
int n, m;
int a[N], b[M], f[40][40][40][40];
int cnt[5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    //cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << cnt[4] << '\n';

    memset(f, 0, sizeof(f));
    f[0][0][0][0] = a[1];
    for(int u1 = 0; u1 <= cnt[1]; u1++) {
        for(int u2 = 0; u2 <= cnt[2]; u2++) {
            for(int u3 = 0; u3 <= cnt[3]; u3++) {
                for(int u4 = 0; u4 <= cnt[4]; u4++) {
                    if(u1 + 1 <= cnt[1])
                        f[u1 + 1][u2][u3][u4] =  max(f[u1 + 1][u2][u3][u4], f[u1][u2][u3][u4] + a[1 + u1 + 1 + 2 * u2 + 3 * u3 + 4 * u4]);
                    if(u2 + 1 <= cnt[2])
                        f[u1][u2 + 1][u3][u4] =  max(f[u1][u2 + 1][u3][u4], f[u1][u2][u3][u4] + a[1 + u1 + 2 * (u2 + 1) + 3 * u3 + 4 * u4]);
                    if(u3 + 1 <= cnt[3])
                        f[u1][u2][u3 + 1][u4] =  max(f[u1][u2][u3 + 1][u4], f[u1][u2][u3][u4] + a[1 + u1 + 2 * u2 + 3 * (u3 + 1) + 4 * u4]);
                    if(u4 + 1 <= cnt[4])
                        f[u1][u2][u3][u4 + 1] =  max(f[u1][u2][u3][u4 + 1], f[u1][u2][u3][u4] + a[1 + u1 + 2 * u2 + 3 * u3 + 4 * (u4 + 1)]);
                }
            }
        }
    }
    cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
    return 0;
}