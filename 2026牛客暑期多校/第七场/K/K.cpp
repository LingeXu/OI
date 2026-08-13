#include <bits/stdc++.h>
#define N 21
using namespace std;
int n;
string s;
vector<string> word[N];
vector<int> prefix[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        prefix[i].push_back(0);
        string s;
        getline(cin, s);
        stringstream ss(s);
        string t;
        while(ss >> t) {
            word[i].push_back(t);
            prefix[i].push_back(prefix[i].back() + (int)t.size());
        }
    }
    
    /*for(int i = 0; i < n; i++) {
        for(string s : word[i])
            cout << s << ' ';
        cout << '\n';
    }*/
    
    vector<string> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = "";
        for(string s : word[i])
            ans[i] += s[0];
        
        //cout << ans[i] << '\n';
        
    }
    for(int i = 1; i < N; i++) {
        unordered_map<string, set<int> > mp;
        for(int j = 0; j < n; j++) 
            mp[ans[j]].insert(j);
        for(auto entry : mp) {
            if(entry.second.size() > 1) 
                for(int rows : entry.second)
                    ans[rows].replace(prefix[rows][i - 1], 1, word[rows][i - 1]);
            
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}