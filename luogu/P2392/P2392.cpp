#include<iostream>
#include<vector>
#define N 25
#define INF 0x3f3f3f3f
using namespace std;
int ans = 0;
int sum = 0;
int s[4], need[4];
vector<int> ti;
void dfs(int pos, int left, int right, int i, vector<int> &ti){
    if(left >= (sum + 1) / 2){
        need[i] = min(left, need[i]);
        return;
    }
    if(right >= (sum + 1) / 2){
        need[i] = min(right, need[i]);
        return;
    }
    dfs(pos + 1, left + ti[pos], right, i, ti);
    dfs(pos + 1, left, right + ti[pos], i, ti);
}
int main(){
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    need[0] = need[1] = need[2] = need[3] = INF;
    for(int i = 0; i < 4; i++){
        sum = 0;
        ti.clear();
        for(int j = 0; j < s[i]; j++){
            int x;
            cin >> x;
            sum += x;
            ti.push_back(x);
        }
        dfs(0, 0, 0, i, ti);
    }
    for(int i = 0; i < 4; i++){
        //cout << need[i] << ' ';
        ans += need[i];
    }
    cout << ans;
    return 0;
}