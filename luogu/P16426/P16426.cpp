#include<iostream>
#define N 1000010
typedef long long ll;
using namespace std;
int main(){
    int n;
    ll t;
    ll a[N];
    cin >> n >> t;
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll sum = 0;
    for(int i = 0; i < n - 1; i++)
        sum += (max(0, (int)(t - max(a[i], a[i + 1]))));
    cout << sum;
    return 0;
}