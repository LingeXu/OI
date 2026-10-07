#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cur = 0;
        bool appear = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(!appear&&a[i] == 1) {
                appear = true;
                continue;
            }
            if(!appear&&a[i] == -1) {
                appear = true;
                a[i] = 1;
            }
        }
        bool appear2 = false;
        for(int i =n-1; i >= 0; i--) {
            if(!appear2 && a[i] == 1) {
                appear2 = true;
                continue;
            }
            if(!appear2&& a[i] == -1) {
                a[i] = 1;
                appear2 = true;
            }
        }
        for(int i = 0; i < n; i++) {
            if(a[i] == -1) {
                cout << 0 << ' ';
                continue;
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}