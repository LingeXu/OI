#include<iostream>
using namespace std;
string out(){
    string ans = "";
    char c;
    while(cin.get(c)){
        if(c == '\n')  break;
        if(c == '['){
            int k;
            cin >> k;
            string pat = out();
            while(k--)
                ans += pat;
        }
        else if(c == ']')
            return ans;
        else    ans += c;
    }
    return ans;
}
int main(){
    cout << out();
    return 0;
}