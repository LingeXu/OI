#include <bits/stdc++.h>
using namespace std;
int t, k, x, y, min_cols = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> k;
        int ans = -1;
        if(k == 1) {
            cout << "YES" << '\n';
            cout << 1 << '\n';
            cout << '*' << '\n';
            cout << '.' << '\n';
            continue;
        }
        if (k % 5 == 0) {
            cout << "YES" << '\n';
            ans = 3 * k / 5;
            cout << ans << '\n';
            for(int i = 1; i <= ans; i++)
                cout << ".";
            cout << '\n';
            for(int i = 1; i <= ans; i++) {
                if(i % 3 == 2)
                    cout << "*";
                else    cout << '.';
            }
            cout << '\n';
            continue;
        }
        if((k - 3) % 5 == 0) {
            cout << "YES" << '\n';
            ans = 3 * (k - 3) / 5 + 2;
            cout << ans << '\n';
            cout << '*';
            for(int i = 2; i <= ans; i++)
                cout << '.';
            cout << '\n';
            cout << "..";
            for(int i = 3; i <= ans; i++) {
                if((i - 2) % 3 == 2) 
                    cout << '*';
                else    cout << '.';
            }
            cout << '\n';
            continue;
        }
        if((k - 6) % 5 == 0) {
            cout << "YES" << '\n';
            ans = 3 * (k - 6) / 5 + 4;
            cout << ans << '\n';
            cout << '*';
            for(int i = 2; i < ans; i++)
                cout << '.';
            cout << '*';
            cout << '\n';
            cout << "..";
            for(int i = 3; i <= ans; i++) {
                if((i - 2) % 3 == 2)
                    cout << '*';
                else    cout << '.';
            }
            cout << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}