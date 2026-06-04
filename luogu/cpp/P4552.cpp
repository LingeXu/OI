#include <bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int n;
ll a[N], diff[N];
map<int, bool> mp;
int main() {
    cin >> n;
    ll positive = 0, negative = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
        if(i >= 2) {
            if(diff[i] >= 0)    positive += diff[i];
            else negative -= diff[i];
        }
    }
    ll operate_cnt = max(positive, negative);
    cout << operate_cnt << '\n';
    cout << abs(positive - negative) + 1;
    return 0;
}