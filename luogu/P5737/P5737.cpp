#include <bits/stdc++.h>
using namespace std;
int x, y, cnt = 0;
vector<int> leap;
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    for(int i = x; i <= y; i++) {
        if(isLeap(i)) {
            leap.push_back(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(auto it = leap.begin(); it != leap.end(); it++)
        cout << *it << ' ';
    return 0;
}