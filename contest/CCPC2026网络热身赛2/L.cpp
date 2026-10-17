#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b, k;
    cin >> n >> b >> k;
    if(k > (n - b) * (n - b + 1) / 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 1; i <= b; i++) {
        if(i < b)   cout << 1 << ' ';
        else    cout << n - b + 1 << '\n';
    }
    for(int i = 1; i < b; i++)
        cout << i << ' ';
    int l = b, r = n, start = r - l;
    int cur = n;
    while(k >= 0) {
        if(k >= cur - l) {
            cout << cur << ' ';
            k -= (cur - l);
            cur--;
            if(cur < l)
                break;
            continue;
        }
        else {
            cout << l + k << ' ';
            for(int i = l; i <= cur; i++) {
                if(i == l + k)  continue;
                cout << i << ' ';
            }
            break;
        }
    }
    return 0;
}