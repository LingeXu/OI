/*#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        int ans = 0;
        for(int i = 0; i < n; ) {
            if(s[i] != '0') {
                i++;
                continue;
            }
            bool ok = false;
            if(i == 0)  ok = true;
            int j = i;
            int cur = 0;
            while(j < n && s[j] == '0') {
                cur++;
                j++;
            }

            //cout << "cur = " << cur << '\n';

            if(!ok)
                ans += max(0, cur - m);
            else    ans += cur;
            i = j;
        }
        cout << ans << '\n';
    }
}*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector<int> id;
        for(int i = 0; i < n; i++)
            if(s[i] == '1')
                id.push_back(i);
        for(int i : id)
            for(int j = i + 1; j <= min(i + m, n - 1); j++)
                s[j] = '1';
        int ans = 0;
        for(char c : s)
            if(c == '0')
                ans++;
        cout << ans << '\n';
    }
    return 0;
}