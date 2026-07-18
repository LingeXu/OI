#include <bits/stdc++.h>
#define N 1000010
#define INF 0x3f3f3f3f
using namespace std;
int n, ans;
int x[N], f[N][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) 
        cin >> x[i];
    f[1][x[1] + 1] = 0;
    for(int i = 2; i <= n; i++) {
        if(x[i] == -1) {
            f[i][0] = f[i - 1][0];
            if(x[i - 1] == 1) {
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
                f[i][2] = min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]) + 2;
            }
            else    f[i][2] = f[i - 1][2] + 2;
        }
        else if(x[i] == 0) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = min(f[i - 1][0], f[i - 1][1]);
            if(x[i - 1] == 1)
                f[i][2] = min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]) + 1;
            else f[i][2] = f[i - 1][2] + 1;
        }
        else {
            f[i][0] = f[i - 1][0] + 2;
            if(x[i - 1] == -1)
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
            else    f[i][1] = f[i - 1][0] + 1;
            f[i][2] =  min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]);
        }
    }
    ans = min(min(f[n][0], f[n][1]), f[n][2]);
    if(ans < INF)   cout << ans;
    else    cout << "BRAK";
    return 0;
}