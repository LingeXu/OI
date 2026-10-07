#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    set<int> zero;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 0)  zero.insert(i);
    } 
    int m = (int)zero.size();
    if(m == 0) {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
            cout << 'A';
        cout << '\n';
        return;
    }
    else if(m == 1) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(zero.find(i) == zero.end())
                cout << 'C';
            else {
                if(cnt == 0) {
                    cout << 'A';
                    cnt++;
                }
                else    cout << 'B';
            }
        }
        cout << '\n';
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}