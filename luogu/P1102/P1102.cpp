#include<iostream>
#include<map>
#include<set>
typedef long long ll;
using namespace std;
set<int> s;
map<int, int> mp;
int main(){
    int n, c;
    ll cnt = 0;
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s.insert(x);
        mp[x]++;
    }
    for(auto it = s.begin(); it != s.end(); it++)
        cnt += 1LL * mp[*it] * mp[*it + c];
    cout << cnt;
    return 0;
}