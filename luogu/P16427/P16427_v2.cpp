#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T > 0){
        int n, x;
        bool ans = 0;
        cin >> n >> x;
        if(x == 1){      
            cout << ((__builtin_popcount(n) == 1) ? "Yes" : "No") << '\n';
            continue;
        }
        vector<int> e;
        e.push_back(1);
        int now = 0;
        while(e[now] * x <= n){
            e.push_back(e[now]*x);
            now++;
        }
        int max_tot = e[now];
        int max_cnt = n, min_cnt = 0;
        while(n > 0){
            min_cnt += n / e[now];
            n -= n / e[now] * e[now];
            now--;
        } 
        for(int i = 1; i <= max_tot; i *= 2){
            if(i <= max_cnt && i >= min_cnt && (i - min_cnt) % (x - 1) == 0){
                ans = 1;
                break;
            }
        }
        ans == 1 ? cout << "Yes" : cout << "No";
        cout << '\n';
        T--;
    }
    return 0;
}