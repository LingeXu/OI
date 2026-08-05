#include <bits/stdc++.h>
#define N 10010
using namespace std;
int n, m;
string s[N];
set<string> name;
map<string, int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        name.insert(s[i]);
    }
    cin >> m;
    while(m--) {
        string q;
        cin >> q;
        if(name.count(q) == 0) {
            cout << "WRONG" << '\n';
            continue;
        }
        else {
            if(++mp[q] == 1) 
                cout << "OK" << '\n';
            else    cout << "REPEAT" << '\n';
            continue;
        }
    }
    return 0;
}