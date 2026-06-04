#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    int k;
    cin >> s >> k;
    int remain = k;
    int maxdigit = 9;
    while(remain > 0){
        int pos = (int)s.find(maxdigit + '0');
        if(pos != -1){
            s.erase(pos, 1);
            remain--;
        }
        else    maxdigit--;
    }
    int start = 0;
    while(start < s.size() - 1 && s[start] == '0')
        start++;
    for(int i = start; i < s.size(); i++)
        cout << s[i];
    return 0;
}