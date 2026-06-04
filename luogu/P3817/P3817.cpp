#include<iostream>
#define N 100010
typedef long long ll;
using namespace std;
ll a[N];
int main(){
    int n;
    ll x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] + a[i + 1] > x){
            ans += (a[i] + a[i + 1] - x);
            a[i + 1] = max(x - a[i], 1LL * 0);
        }
    }
    cout << ans;
    return 0;
}