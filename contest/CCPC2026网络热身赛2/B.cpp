#include <bits/stdc++.h>
using namespace std;
int main() {
    int l = 0, r = 1e9, ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        cout << "? " << mid << endl;
        int resp;
        cin >> resp;
        if(resp == 0) {
            l = mid + 1;
            continue;
        }
        else {
            r = mid - 1;
            ans = mid;
            continue;
        }
    }
    cout << "! " << ans << endl;
}

