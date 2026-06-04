#include<iostream>
typedef long long ll;
using namespace std;
int main(){
    ll n, m, d;
    cin >> n >> m >> d;
    if(n * (d + 1) > m){
        cout << -1;
        return 0;
    }
    else if(n * (d + 2) <= m){
        cout << n + (m - n * (d + 2)) / (d + 1);
        return 0;
    }
    else{
        cout << m - n * (d + 1);
        return 0;
    }
    return 0;
}