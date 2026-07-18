#include <bits/stdc++.h>
#define N 110
#define M 110
using namespace std;
int n, m;
char c[N][M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    return 0;
}