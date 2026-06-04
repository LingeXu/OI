#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#define LOG 18
using namespace std;
vector<int> op2_cnt[LOG];
vector<int> ans;
int main(){
    int t;
    cin >> t;
    while(t > 0){
        ans.clear();
        int n, x;
        cin >> n >> x;
        int max_op2 = (int)log2(n);
        op2_cnt[0].clear();
        int start = 1;
        while(start <= n){
            op2_cnt[0].push_back(start);
            start *= x;
        }
        ans.insert(ans.end(), op2_cnt[0].begin(), op2_cnt[0].end());
        for(int i = 1;i <= max_op2; i++){
            op2_cnt[i].clear();
            set<int> s;
            for(int j = 0; j < op2_cnt[i - 1].size(); j++)
                for(int k = j; k < op2_cnt[i - 1].size(); k++)
                    s.insert(op2_cnt[i - 1][j] + op2_cnt[i - 1][k]);
            op2_cnt[i] = vector<int>(s.begin(), s.end());
            ans.insert(ans.end(), op2_cnt[i].begin(), op2_cnt[i].end());
        }
        if(count(ans.begin(), ans.end(), n) == 0)
            cout << "No" << '\n';
        else    cout << "Yes" << '\n'; 
        t--;
    }
    return 0;
}