#include <bits/stdc++.h>
#define N 10010
using namespace std;
int height[N];
bool record[N];
int main() {
    int l, h, r;
    while(cin >> l >> h >> r) {
        for(int i = l; i < r; i++) 
            height[i] = max(height[i], h);
        record[l] = record[r] = true;
    }
    for(int i = 1; i < N; i++)
        if(record[i] && height[i] != height[i - 1])
            cout << i << ' ' << height[i] << ' ';
    return 0;
}