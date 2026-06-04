#include <bits/stdc++.h>
const int N = 2e4 + 10;
using namespace std;
int n;
int a[N], b[N];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (b[i] - a[i]);
        if(i != 0 && a[i] < b[i - 1])
            ans -= (b[i - 1] - a[i]);
    }
    cout << ans;
    return 0;
}