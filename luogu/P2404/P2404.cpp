#include<iostream>
#include<cstring>
#include<algorithm>
#define N 25
using namespace std;
int n;
int ans[N];
void dfs(int pre, int remain, int pos){
    if(remain == 0 && ans[0] != n){
        for(auto i = 0; i < pos - 1; i++)   cout << ans[i] << '+';
        cout << ans[pos - 1] << '\n';
        return;
    }
    if(pre > remain)    return;
    for(int i = pre; i <= remain; i++){
        ans[pos] = i;
        dfs(i, remain - i, pos + 1);
    }
}
int main(){
    cin >> n;
    dfs(1, n, 0);
    return 0;
}