#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << fixed << setprecision(6) << (double)n * (n - 1) / 2 + 1 << '\n';
}