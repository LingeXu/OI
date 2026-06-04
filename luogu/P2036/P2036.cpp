#include<iostream>
#include<vector>
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;
int n, ans = INF;
struct flavour{
    int s, b;
};
vector<flavour> ingredient;
void dfs(int SumOfSour, int SumOfBitter, int pos, int cnt){
    if(cnt != 0)
        ans = min(ans, abs(SumOfSour - SumOfBitter));
    if(pos == n)    return;
    dfs(SumOfSour, SumOfBitter, pos + 1, cnt);
    dfs(SumOfSour * ingredient[pos].s, SumOfBitter + ingredient[pos].b, pos + 1, cnt + 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int sour, bitter;
        cin >> sour >> bitter;
        ingredient.push_back({sour, bitter});
    }
    dfs(1, 0, 0, 0);
    cout << ans;
    return 0;
}