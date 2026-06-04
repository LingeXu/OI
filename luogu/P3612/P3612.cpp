#include<iostream>
#define TOT 64
typedef long long ll;
using namespace std;
string s;
ll n;
string ans[TOT];
string GetAns(ll x){
    if(ans[x] != "")    return ans[x];
    if(x == 0)  return ans[0] = s;
    string pat = GetAns(x - 1);
    char c = pat.back();
    return ans[x] = pat + c + pat.substr(0, pat.size() - 1);
}
int main(){
    cin >> s >> n;
    int tot = 0, now = s.size();
    while(1){
        if(now >= n)
            break;
        now <<= 1;
        tot++;
    }
    string ob = GetAns(tot);
    cout << ob[n - 1];
    return 0;
}