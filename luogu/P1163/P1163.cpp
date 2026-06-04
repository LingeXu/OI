#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<double> remain;
int w0, w, m;
bool check(double x){
    remain.clear();
    remain.push_back(double(w0));
    while(1){
        double last = remain.back();
        double nextmonth = last + last * x / 100.0 - w;
        if(nextmonth > 0){
            remain.push_back(nextmonth);
            if(remain.size() > m)
                return false;
        }
        else    break;
    }
    return remain.size() <= m;
}
int main(){
    cin >> w0 >> w >> m;
    double left = 0.0, right = 300.0, ans = 0.0;
    //cout << check(2.8) << ' ' << check(2.9);
    //cout << check(2.85645) << '\n';
    while(right - left >= 1e-9){
        double mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            left = mid;
            //cout << ans << ' ' << left << ' ' << right << '\n';
        }
        else{
            right = mid;
            //cout << left << ' ' << right << '\n';
        }
    }
    //cout << ans;
    cout << fixed << setprecision(1) << ans;
    return 0;
}