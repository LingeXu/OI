#include<iostream>
#include<vector>
#define N 1010
using namespace std;
int m, n;
vector<int> dp[N];
vector<int> add(vector<int> a, vector<int> b){
    vector<int> c;
    int carry = 0;
    for(int i = 0; i < a.size() || i < b.size() || carry != 0; i++){
        int now = carry;
        if(i < a.size())    now += a[i];
        if(i < b.size())    now += b[i];
        c.push_back(now % 10);
        carry = now / 10;
    }
    return c;
}
vector<int> GetSum(int x){
    vector<int> temp;
    if(x < m){
        temp.push_back(0);
        return temp;
    }
    if(!dp[x].empty())   return dp[x];
    return dp[x] = add(GetSum(x - 2), GetSum(x - 1));
}
int main(){
    cin >> m >> n;
    dp[m].push_back(1);
    vector<int> ans = GetSum(n);
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}