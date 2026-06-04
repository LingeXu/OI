#include<iostream>
#include<vector>
#include<iomanip>
typedef long long ll;
using namespace std;
int n, p;
struct device{
    int a, b;
};
vector<device> d;
bool check(double x){
    double tot = 0;
    for(auto& v : d){
        double need = v.a * x - v.b;
        if(need <= 1e-12)
            continue;
        tot +=  need / p;
        if(tot > x)
            return false;
    }
    return tot <= x;
}
int main(){
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        d.push_back({a, b});
    }
    ll SumOfCost = 0;
    for(auto it = d.begin(); it != d.end(); it++){
        SumOfCost += it->a;
        if(SumOfCost > p)
            break;
    }
    if(SumOfCost <= p){
        cout << -1;
        return 0;
    }
    double left = 0.0, right = 1e15;
    int cnt = 0;
    while(++cnt < 100){
        double mid = (left + right) / 2;
        if(check(mid)){
            left = mid;
            //cout << left << ' ' << right << '\n';
        }
        else{
            right =mid;
            //cout << left << ' ' << right << '\n';
        }   
    }
    cout << fixed << setprecision(10) << left;
    return 0;
}