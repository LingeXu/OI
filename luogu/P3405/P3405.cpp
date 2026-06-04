#include<iostream>
#include<map>
using namespace std;
map<string, int> mp;
int main(){
    int n, ans = 0;
    cin >> n;
    while(n > 0){
        string city, state;
        cin >> city >> state;
        string s1 = city.substr(0, 2) + state;
        string s2 = state + city.substr(0, 2);
        mp[s1]++;
        if(s1 != s2)
            ans += mp[s2];
        n--;
    }
    cout << ans;
    return 0;
}