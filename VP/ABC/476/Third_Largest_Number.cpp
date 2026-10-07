#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mx = 0, mn = 0, aim = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x >= mx) {
            aim = mn;
            mn = mx;
            mx = x;
        }
        else if(mn <= x && x < mx) {
            aim = mn;
            mn = x;
            
        }
        else if(x < mn && x >= aim) {
            aim = x;
            
        }
        if(i >= 2)
            cout << aim << '\n';
    }
}