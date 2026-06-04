#include<iostream>
#include<algorithm>
#define M 5050
typedef long long ll;
using namespace std;
struct farmer{
    int price, provide;
}f[M];
bool cmp(farmer a, farmer b){
    return a.price < b.price;
}
int main(){
    int n, m, need;
    ll ans = 0;
    cin >> n >> m;
    need = n;
    for(int i = 0; i < m; i++){
        int q, a;
        cin >> q >> a;
        f[i].price = q;
        f[i].provide = a;
    }
    sort(f, f + m, cmp);
    int start = 0;
    while(start < m){
        ans += 1LL * f[start].price * min(need, f[start].provide);
        //cout << ans << ' ' << need << ' ';
        need -= min(need, f[start].provide);

        if(need == 0)
            break;
        start++;
    }
    cout << ans;
    return 0;
}