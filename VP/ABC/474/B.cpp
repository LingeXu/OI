#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int group = (i - 1) / 10;
        if(x > (group + 1) * 10 || x <= group * 10)
            ok = false;
    }
    if(ok) {
        cout << "Yes";
    }
    else    cout << "No";
    return 0;
}