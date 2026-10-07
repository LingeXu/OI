#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        cout << (1LL << (n - k + 1)) - 2 + 2 * k << '\n';
    }
    return 0;
}