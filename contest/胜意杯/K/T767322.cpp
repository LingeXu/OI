#include <bits/stdc++.h>
#define MAXS 100010
using namespace std;
int n, m;
char c[MAXS];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bool ok1 = true, ok2 = true;
    if(n == 1 || m == 1) {
        cout << "NO";
        return 0;
    }
    for(int i = 1; i <= n * m; i++) {
        cin >> c[i];
        if(i <= m && c[i] == '#')
            ok1 = false;
        if(i % m == 0 && c[i] == '#')
            ok1 = false;
        if(i % m == 1 && c[i] == '#')
            ok2 = false;
        if(i > (n - 1) * m && c[i] == '#')
            ok2 = false;
    }
    cout << (ok1 || ok2 ? "YES" : "NO");
    return 0;
}