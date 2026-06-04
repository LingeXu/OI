#include<iostream>
using namespace std;
void dfs(int x){
    if(x == 1){
        cout << "2(0)";
        return;
    }
    if(x == 2){
        cout << "2";
        return;
    }
    int bit = 0, now = 1;
    while(1){
        if(now > x)
            break;
        bit++;
        now <<= 1;
    }
    if(bit - 1 == 1)
        cout << "2";
    else{
        cout << "2(";
        dfs(bit - 1);
        cout << ')';
    }
    int next = x - (1 << (bit - 1));
    if(next != 0){
        cout << '+';
        dfs(next);
    }
}
int main(){
    int n;
    cin >> n;
    dfs(n);
    return 0;
}