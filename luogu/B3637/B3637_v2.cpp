#include <bits/stdc++.h>
#define N 5050
using namespace std;
int n;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<int> d;
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        if(it == d.end()) 
            d.push_back(a[i]);
        else    *it = a[i];
    }
    cout << d.size();
    return 0;
}