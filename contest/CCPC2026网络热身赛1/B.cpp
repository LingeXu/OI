#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int a, int p, int &i, int &x, int c) {
    if(a == 0) {
        i = 0;
        x = c / p;
        return p;
    }
    int i1, x1;
    int gcd = solve(p % a, a, i1, x1, c);
    x = i1;
    i = x1 - p / a * i1;
    return gcd;
}
signed main() {
    int p, y;
    cin >> p >> y;
    cout << "? " << 0 << endl;
    int resp1;
    cin >> resp1;
    int b = resp1;
    cout << "? " << 1 << endl;
    int resp2;
    cin >> resp2;
    int a = (resp2 - resp1 + p) % p;
    int i, x;
    //cout << "a = " << a << ", p = " << p << ", c = " << y - b << '\n';
    solve(a, p, i, x, y - b);
    cout << "! " << (i % p + p) % p;
    return 0;
}