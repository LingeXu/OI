#include <bits/stdc++.h>
#define N 2020
using namespace std;
string a, b;
int f[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int m = a.size(), n = b.size();
    memset(f, 0x3f, sizeof(f));
    for(int i = 0; i <= m; i++)
        f[i][0] = i;
    for(int i = 0; i <= n; i++)
        f[0][i] = i;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else 
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
        }   
    }
    cout << f[m][n];
    return 0;
}