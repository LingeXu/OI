#include<iostream>
#define N 25
typedef long long ll;
using namespace std;
ll ans[N][N][N];
ll GetAns(ll a, ll b, ll c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return GetAns(20, 20, 20);
    if(ans[a][b][c] != 0)
        return ans[a][b][c];
    if(a < b && b < c)
        return ans[a][b][c] = GetAns(a, b, c - 1) + GetAns(a, b - 1, c - 1) - GetAns(a, b - 1, c);
    return ans[a][b][c] = GetAns(a - 1, b, c) + GetAns(a - 1, b - 1, c) + GetAns(a - 1, b, c - 1) - GetAns(a - 1, b - 1, c - 1);
}
int main(){
    ll a, b, c;
    while(cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)){
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, GetAns(a, b, c));
    }
    return 0;
}