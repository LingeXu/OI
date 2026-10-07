#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = 0, mx = 0;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    if (sum - mx >= n||sum==0 ) {
        cout << "Puss in Boots";
    } else {
        cout << "Donkey";
    }
    return 0;
}