#include<iostream>
#include<vector>
#define N 1010
#define W 10010
const int MOD = 1e9 + 7;
using namespace std;
int n, w;
int price[N];
int dp[N][W];
int main(){
    cin >> n >> w;
    for(int i = 0; i < n; i++)  cin >> price[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            if(i == 0){
                dp[0][j] = (j % price[0] == 0);
                continue;
            }
            if(j - price[i] < 0)
                dp[i][j] = dp[i - 1][j];
            else    dp[i][j] = (dp[i - 1][j] + dp[i][j - price[i]]) % MOD; 
        }
    }
    cout << dp[n - 1][w];
    return 0;
}