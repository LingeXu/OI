#include <bits/stdc++.h>
using namespace std;
int n, m;
void solve() {
    cin >> n >> m;
    if(m < n || m > 2 * n - 1) {
        cout << -1 << '\n';
        return;
    }
    vector< vector<int> > a(n + 1, vector<int>(n + 1));
    int diff = 2 * n - m;
    for(int i = 1; i <= diff; i++) 
        a[i][i] = i;
    int cur = diff + 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 0)
                a[i][j] = cur++;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)  solve();
}