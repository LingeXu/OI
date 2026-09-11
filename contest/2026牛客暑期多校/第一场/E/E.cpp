#include <bits/stdc++.h>
#define N 200020
typedef long long ll;
using namespace std;
int n;
ll sum = 0;
int p[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        sum += (2 * i - n + 1) * p[i];
    }
    cout << sum;
    return 0;
}