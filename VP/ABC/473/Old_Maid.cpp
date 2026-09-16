#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sum = 0;
    map<int, bool> mp;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        if(mp[x] == true) {
            mp[x] = false;
            sum -= 2 * x;
        }
        else {
            mp[x] = true;
        }
    }
    cout << sum;
    return 0;
}