#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    // c = (x - P[k] + n) % n
    int c = (x - P[k] + n) % n;

    for (int i = 0; i < n; i++) {
        cout << (P[i] + c) % n << " \n"[i == n - 1];
    }

    return 0;
}
