#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        if(n == 1) {
            cout << a[0] << '\n';
            continue;
        }
        if(a[0] > a[n - 1])
            swap(a[0], a[n - 1]);
        cout << gcd(a[0], a[n - 1]) << '\n';
    }
    return 0;
}