#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    if(s[n - 1] == 'e') {
        cout << s << 'r';
    }
    else    cout << s << "er";
    return 0;
}