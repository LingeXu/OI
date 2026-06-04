#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
vector<int> height;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        height.push_back(h);
    }
    sort(height.begin(), height.end());
    int last = 0;
    ll ans = 0;
    while(height.size() > 0){
        int maxheight = height.back(), minheight = height[0];
        ans += 1LL * (maxheight - last) * (maxheight - last) +1LL *  (maxheight - minheight) * (maxheight - minheight);
        last = minheight;
        height.erase(prev(height.end()));
        height.erase(height.begin());
        if(height.size() == 1){
            ans += (height[0] - last) * (height[0] - last);
            break;
        }
    }
    cout << ans;
    return 0;
}