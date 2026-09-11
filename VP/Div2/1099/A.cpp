#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = n + 1; i <= 2 * n; i++)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}