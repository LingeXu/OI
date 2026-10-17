#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        stack<int> st;
        vector<int> printed(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                st.push(i + 1);
            }
            else if(s[i] == '2') {
                if(!st.empty()) {
                    printed[st.top()] = 1;
                    st.pop();
                }
                else    printed[i + 1] = 1;
            }
            else {
                printed[i + 1] = 1;
            }
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++)
            if(printed[i] == 0)
                ans.push_back(i);
        cout << (int)ans.size() << '\n';
        for(int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}