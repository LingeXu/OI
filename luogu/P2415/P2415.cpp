#include <bits/stdc++.h>
typedef long long ll;
#define N 30
using namespace std;
int n = 0;
vector<int> ans, base;
vector<int> add(vector<int> x, vector<int> y) {
    vector<int> res;
    int carry = 0;
    for(int i = 0; i < x.size() || i < y.size() || carry != 0; i++) {
        int now = carry;
        if(i < x.size())
            now += x[i];
        if(i <y.size())
            now += y[i];
        res.push_back(now % 10);
        carry = now / 10;
    }
    return res;
}
vector<int> multiply(vector<int> x, vector<int> y) {
    vector<int> res(x.size() + y.size() + 2);
    for(int i = 0; i < x.size(); i++) 
        for(int j = 0; j < y.size(); j++) 
            res[i + j] += x[i] * y[j];
    int carry = 0;
    for(int i = 0; i < res.size(); i++) {
        int now = res[i] + carry;
        res[i] = now % 10;
        carry = now / 10;
    }
    return res;
}
vector<int> quick_pow(int x, int y) {
    vector<int> res;
    vector<int> x_vec;
    x_vec.push_back(x);
    res.push_back(1);
    while(y > 0) {
        if(y & 1) 
            res = multiply(res, x_vec);
        x_vec = multiply(x_vec, x_vec);
        y >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ans.push_back(0);
    int x;
    base.push_back(2);
    while(cin >> x) {
        n++;
        vector<int> x_vec;
        x_vec.push_back(x);
        ans = add(multiply(ans, base), multiply(x_vec, quick_pow(2, n - 1)));
    }
    reverse(ans.begin(), ans.end());
    int start = 0;
    while(start < ans.size() && ans[start] == 0)
        start++;
    if(start == ans.size()) {
        cout << 0;
        return 0;
    }
    for(auto it = ans.begin() + start; it != ans.end(); it++)
        cout << *it;
    return 0;
}