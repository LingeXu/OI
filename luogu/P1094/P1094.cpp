#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> price;
int main(){
    int w, n, ans = 0;
    cin >> w >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        price.push_back(p);
    }
    sort(price.begin(), price.end());
    while(price.size() > 1){
        int minp = price[0], maxp = price.back();
        if(minp + maxp > w){
            ans++;
            price.erase(prev(price.end()));
        }
        else{
            price.erase(price.begin());
            price.erase(prev(price.end()));
            price.push_back(minp + maxp);
        }
    }
    cout << ans + 1;
    return 0;
}