#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> ans;
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] == '1')
                ans.push_back(i + 1);
        }
        if((int)ans.size() % 2 != 0 && n % 2 != 0) {
            cout << -1 << '\n';
        }
        else if((int)ans.size() % 2 == 0 ){
            cout << (int)ans.size() << '\n';
            if((int)ans.size() == 0)    continue;
            for(int i = 0; i < (int)ans.size(); i++)
                cout << ans[i] << ' ';
            cout << '\n';
        }
        else {
            vector<int> ans2;
            for(int i = 0; i < (int)s.size(); i++)
                if(s[i] == '0')
                    ans2.push_back(i + 1);
            cout << (int)ans2.size() << '\n';
            if((int)ans2.size() == 0)    continue;
            for(int i = 0; i < (int)ans2.size(); i++)
                cout << ans2[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}