#include <bits/stdc++.h>
using namespace std;
bool query(int l, int r, int extra) {
    cout << "? " << r - l + 1 + (extra != 0) << ' ';
    for(int i = l; i <= r; i++) 
        cout << i << ' ';
    if(extra != 0)  cout << extra;
    cout << endl;
    int resp;
    cin >> resp;
    if((r - l + 1 + (extra != 0) - resp) & 1)   return true;
    return false;
}
int t, n;
void solve() {
    cin >> n;
    int l1 = 1, r1 = 2 * n + 1, R;
    while(l1 <= r1) {
        int mid = l1 + ((r1 - l1) >> 1);
        if(query(1, mid, 0)) {
            R = mid;
            r1 = mid - 1;
        }
        else    l1 = mid + 1;   
    }
    int l2 = 1, r2 = 2 * n + 1, L;
    while(l2 <= r2) {
        int mid = l2 + ((r2 - l2) >> 1);
        if(query(mid, 2 * n + 1, 0)) {
            L = mid;
            l2 = mid + 1;
        }
        else    r2 = mid - 1;   
    }
    int l3 = L + 1, r3 = R - 1, M;
    while(l3 <= r3) {
        int mid = l3 + ((r3 - l3) >> 1);
        if(query(1, mid, R)) {
            M = mid;
            r3 = mid - 1;
        }
        else    l3 = mid + 1;
    }
    cout << "! " << L << ' ' << M << ' ' << R << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}