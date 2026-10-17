#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    a[0] = n;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    for(int i = 1; i <= n; i++) {
        if(i - 1 >= 1 && i - 1 <= n)
            cout << a[i - 1] << ' ';
        else    cout << a[(i - 1 + 100 * n) % n] << ' ';
    }
    for(int i = 1; i <= n; i++) {
        if(i - 3 >= 1 && i - 3 <= n)
            cout << a[i - 3] << ' ';
        else    cout << a[(i - 3 + 100 * n) % n] << ' ';
    }
    for(int i = 1; i <= n; i++) {
        if(i - 6 >= 1 && i - 6 <= n)
            cout << a[i - 6] << ' ';
        else {
            
            cout << a[(i - 6 + 100 * n) % n] << ' ';
        }
    }
    cout << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}