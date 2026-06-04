#include<iostream>
#include<vector>
#define N 5050
using namespace std;
vector<int> dp[N];
vector<int> add(vector<int> a, vector<int> b){
    vector<int> c;
    int carry = 0;
    for(int i = 0; i < a.size() || i <b.size() || carry != 0; i++){
        int now = carry;
        if(i < a.size())    now += a[i];
        if(i < b.size())    now += b[i];
        c.push_back(now % 10);
        carry = now / 10;
    }
    return c;
}
int main(){
    int n;
    cin >> n;
    dp[1].push_back(1);
    dp[2].push_back(2);
    for(int i = 3; i <= n; i++)
        dp[i] = add(dp[i - 1], dp[i - 2]);
    for(int i = dp[n].size() - 1; i >=0; i--)
        cout << dp[n][i];
    return 0;
}