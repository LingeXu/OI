#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            for(int j = 1; j <= a; j++) {
                for(int k = 1; k <= n; k++) {
                    for(int m = 1; m <= b; m++) {
                        if(k & 1)
                            cout << '.';
                        else {
                            cout << '#';
                        }
                    }
                }
                cout << '\n';
            }
        }
        else {
            for(int j = 1; j <= a; j++) {
                for(int k = 1; k <= n; k++) {
                    for(int m = 1; m <= b; m++) {
                        if(k & 1)
                            cout << '#';
                        else {
                            cout << '.';
                        }
                    }
                }
                cout << '\n';
            }
        }
    }
    return 0;
}