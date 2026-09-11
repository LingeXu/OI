#include <bits/stdc++.h>
#define N 500000
using namespace std;
int a, b, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    for(int i = 1; i <= a; i++)
        cout << 3;
    for(int i = a + 1; i < N; i++)
        cout << 9;
    cout << ' ';
    cout << 3;
    for(int i = 2; i <= b; i++)
        cout << 0;
    for(int i = b + 1; i < N; i++)
        cout << 9;
    cout << ' ';
    for(int i = 1; i <= a; i++)
        cout << 3;
    for(int i = a + 1; i < N; i++)
        cout << 0;
    cout << ' ';
    cout << 3;
    for(int i = 2; i < N; i++)
        cout << 0;
    return 0;
}