#include<iostream>
#include<vector>
using namespace std;
vector<int> dis;
int l, n, k;
bool check(int x){
    int sum = 0;
    for(int d : dis)
        sum += (d % x == 0 ? d / x - 1 : d / x);
    return sum <= k;
}
int main(){
    cin >> l >> n >> k;
    int last = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(i != 1)
            dis.push_back(x - last);
        last = x;
    }
    int left = 1, right = l, ans = l;
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