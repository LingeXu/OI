#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size() - 1; i += 2)
        s.insert(i + 1, "o");
    cout << s;
}