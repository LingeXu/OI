#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int a, int b, int& x1, int& y1, int m) {
    if(a == 0) {
        x1 = b;
        y1 = m;
        return b;
    }
    int x2, y2;
    int gcd = solve(b % a, a, x2, y2, m);
    y1 = x2;
    x1 = y2 - b / a * x2;
    return gcd;
}
signed main() {
    int p, y;
    cin >> p >> y;
    cout << "? " << 0 << endl;
    int resp1;
    cin >> resp1;
    cout << "? " << 1 << endl;
    int resp2;
    cin >> resp2;
    int b = resp1, a = (resp2 - resp1 + p) % p;
    int x1, y1;
    //solve(3, 7, x1, y1, 3);
    solve(a, p, x1, y1, (y - b + p) % p);
    cout << "! " << (x1 % p + p) % p << endl;
    return 0;
}