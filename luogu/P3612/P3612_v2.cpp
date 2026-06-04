#include<iostream>
typedef long long ll;
using namespace std;
int main(){
    string s;
    ll n;
    cin >> s >> n;
    ll now = s.size();
    while(1){
        if(now >= n)
            break;
        now <<= 1;
    }
    while(n > s.size()){
       if(n > now / 2){
            n -= now / 2;
            if(n == 1)  n = now / 2;
            else    n--;
        }
        now /= 2;
    }
    cout << s[n - 1];
    return 0;
}