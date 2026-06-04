#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        vector<int> ans;
        unordered_set<int> s;
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(!s.count(x)){
                s.insert(x);
                ans.push_back(x);
            }
        }
        cout << ans[0];
        for(int j = 1; j < ans.size(); j++)
            cout << ' ' << ans[j];
        cout << '\n';
    }
    return 0;
}