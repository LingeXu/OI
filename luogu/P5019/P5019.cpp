#include<iostream>
#include<vector>
using namespace std;
vector<int> depth;
int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        depth.push_back(d);
    }
    ans += depth[0];
    for(int i = 1; i < depth.size(); i++)
        ans += max(depth[i] - depth[i - 1], 0);
    cout << ans;
    return 0;
}