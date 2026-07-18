#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
int a[N], b[N], c[N];
map<int, int> mp;
vector<int> d;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = mp[b[i]];
    }
    for(int i = 1; i <= n; i++) {
        auto it = lower_bound(d.begin(), d.end(), c[i]);
        if(it == d.end()) 
            d.push_back(c[i]);
        else    *it = c[i];
    }
    cout << d.size();
    return 0;
}