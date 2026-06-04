#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> AppleCanReach;
int main(){
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(x <= a + b)
            AppleCanReach.push_back(y);
    }
    sort(AppleCanReach.begin(), AppleCanReach.end());
    int remain = s, cnt = 0;
    auto it = AppleCanReach.begin();
    while(it != AppleCanReach.end()){
        remain -= *it;
        if(remain < 0)
            break;
        cnt++;
        it++;
    }
    cout << cnt;
    return 0;
}