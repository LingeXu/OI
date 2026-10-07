#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        char aim = s.back();
        int cnt = 0;
        for(int i = 0; i < n; i++) 
            if(s[i] != aim)
                cnt++;
        cout << cnt << '\n';
    }
    return 0;
}