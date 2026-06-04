#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int p;
vector<int> result, base;
vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<int> res(500);
    for(int i = 0; i < (int)a.size(); i++)
        for(int j = 0; j < (int)b.size(); j++)
            if(i + j < 500)
                res[i + j] += a[i] * b[j];
    int carry = 0;
    for(int i = 0; i < 500; i++) {
        int now = carry + res[i];
        res[i] = now % 10;
        carry = now / 10;
    }
    if(res.size() > 500)
        res.erase(res.begin() + 501, res.end());
    return res;
}
void quick_pow(vector<int>& base, int& p) {
    while(p > 0) {
        if(p & 1) 
            result = multiply(result, base);
        base = multiply(base, base);
        p >>= 1;
    }
}
int main() {
    cin >> p;
    int ans = (floor)((double)p * log10(2)) + 1;
    cout << ans << '\n';
    base.push_back(2);
    result.push_back(1);
    quick_pow(base, p);
    int cnt = 0;
    int patch = max(0, 500 - (int)result.size());
    for(int i = 0; i < patch; i++) {
        cout << '0'; 
        cnt++;
        if(cnt == 50) {
            cout << '\n';
            cnt = 0;
        }
    }
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] - (i != 0 ? 0 : 1);
        cnt++;
        if(cnt == 50) {
            cout << '\n';
            cnt = 0;
        }
    }
    return 0;
}