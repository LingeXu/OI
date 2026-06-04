#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
int n, m;
ll sum = 0;
vector<int> v;
bool check(int x){
    for(int i = 0; i < n; i++)
        if(v[i] > x)
            return false;
    int now = 0, cnt = 1;
    for(int i = 0; i < n; i++){
        if(now + v[i] <= x)
            now += v[i];
        else{
            cnt++;
            now = 0;
            i--;
        }
    }
    return cnt <= m;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        sum += v[i];
    }
    //cout << check(5) << ' ' << check(6) << ' ' << check(7);
    ll left = 0, right = sum, ans = sum;
    while(left <= right){
        int mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            right = mid - 1;
            continue;
        }
        if(!check(mid))
            left = mid + 1;
    }
    cout << ans;
    return 0;
}