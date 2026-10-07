#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, n;
        cin >> a >> b >> n;
        if(n == 1 || a == b) {
            cout << 1 << '\n';
            continue;
        }
        int aim = a / b;
        if(n <= aim) {
            cout << 1 << '\n';
            continue;
        }
        cout << 2 << '\n';
    }
}