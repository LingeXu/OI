#include<iostream>
using namespace std;
string split(int x){
    if(x == 0 || x == 2)
        return to_string(x);
    vector<int> has_num;
    int cnt = 0;
    while(x != 0){
        if(x & 1){
            has_num.push_back(cnt);
            //cout << cnt << ' ';
        }
        x >>= 1;
        //cout << x;
        cnt++;
    }
    string splited = "";
    for(auto it = prev(has_num.end()); it != prev(has_num.begin()); it--){
        if(it != prev(has_num.end()))
            splited += '+';
        if(*it != 1){
            splited += "2(";
            splited += to_string(*it);
            splited += ')';
        }
        else    splited += "2";
    }
    return splited;
}
string expand(string s){
    string ans = "";
    int digit = 0;
    for(auto it = s.begin(); it != s.end(); it++){
        if(*it == '('){
            ans += '(';
            digit = 0;
            it++;
            while(it != s.end() && isdigit(*it)){
                digit = digit * 10 + *it - '0';
                it++;
            }
            ans +=split(digit);
            it--;
        }
        else    ans += *it;
    }
    return ans;
}
int main(){
    //cout << split(1024) << '\n';
    int n;
    cin >> n;
    string s = split(n);
    int remain  = 30;
    while(remain--)
        s = expand(s);
    cout << s;
    return 0;
}