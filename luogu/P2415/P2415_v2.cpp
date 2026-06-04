#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int cnt = 0;
ll ans = 0, sum = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    while(cin >> x) {
        cnt++;
        sum += x;
    }
    cout << sum * (1 << (cnt - 1));
    return 0;
}