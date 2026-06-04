#include<iostream>
#include<vector>
#include<stdio.h>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, x;
        bool ans = 0;
        cin >> n >> x;
        
        if(x == 1){      
            cout << ((__builtin_popcount(n) == 1) ? "Yes" : "No") << '\n';
            continue;
        }
        vector<ll> e;
        e.push_back(1);
        int now = 0;
        while(e[now] * x <= n){
            e.push_back(e[now] * x);
            now++;
        }
        int max_cnt = n, min_cnt = 0;
        //int temp_n = n;  
        while(n > 0){
            min_cnt += n / e[now];
            n %= e[now];
            now--;
        }
        
        for(ll i = 1; i <= max_cnt; i <<= 1){  
            if(i >= min_cnt && (i - min_cnt) % (x - 1) == 0){
                ans = 1;
                break;
            }
        }
        
        cout << (ans ? "Yes" : "No") << '\n';
    }
    return 0;
}