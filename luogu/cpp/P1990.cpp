#include<iostream>
#define N 1000010
typedef long long ll;
ll tot[2 * N];
using namespace std;
ll GetTot(int x){
    if(x == 2)
        return tot[x] = 1;
    if(x == 3)
        return tot[x] = 1;
    if(x == 4)
        return tot[x] = 2;
    if(tot[x] != 0)
        return tot[x];
    if(x & 1)
        return tot[x] = (GetTot(x - 2) + GetTot(x - 3)) % 10000;
    else    return tot[x] = (GetTot(x - 2) + GetTot(x - 4) + 2 * GetTot(x - 3)) % 10000;
}
int main(){
    int n;
    cin >> n;
    cout << GetTot(2 * n);
    return 0;
}