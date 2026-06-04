#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
double a, b, c, d;
int result(double x){
    if(a * x * x * x + b * x * x + c * x + d > 1e-9)
        return 1;
    else if(a * x * x * x + b * x * x + c * x + d < -1e-9)
        return -1;
    return 0;
}
vector<double> ans;
void output(){
    cout << fixed << setprecision(2) << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}
bool exist(double x){
    for(double v : ans)
        if(fabs(x - v) < 1e-9)
            return true;
    return false;
}
int main(){
    cin >> a >> b >> c >> d;
    for(int i = -100; i < 100; i++){
        double left = 1.00 * i, right = 1.00 * (i + 1);
        if(result(left) == 0 && !exist(left)){
            ans.push_back(left);
            if(ans.size() == 3){
                output();
                return 0;
            }
        }
        if(result(right) == 0){
            ans.push_back(right); 
            if(ans.size() == 3){
                output();
                return 0;
            }
            continue;
        }
        if(result(left) == 1 && result(right) == -1){
            for(int i = 0; i < 100; i++){
                double mid = (left + right) / 2;
                if(result(mid) == 1)
                    left = mid + 1e-9;
                if(result(mid) == -1)
                    right = mid - 1e-9;
            }
            double root = (left + right) / 2;
            ans.push_back(root);
            if(ans.size() == 3){
                output();
                return 0;
            }
            continue;
        }
        if(result(left) == -1 && result(right) == 1){
            for(int i = 0; i < 100; i++){
                double mid = (left + right) / 2;
                if(result(mid) == 1)
                    right = mid - 1e-9;
                if(result(mid) == -1)
                    left = mid + 1e-9;
            }
            double root = (left + right) / 2;
            ans.push_back(root);
            if(ans.size() == 3){
                output();
                return 0;
            }
            continue;
        }
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}