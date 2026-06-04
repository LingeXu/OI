#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string GetAns(string s){
    if(!(s[0] == '[' && s.back() == ']'))
        return s;
    else{
        string ans = "";
        int repeat = 0, start;
        for(int i = 1; i < s.size(); i++){
            if(isdigit(s[i]))
                repeat = repeat * 10 + (s[i] - '0');
            else{
                start = i;
                break;
            }
        }
        string pat = GetAns(s.substr(start, s.size() - start - 1));
        for(int i = 1; i <= repeat; i++)
            ans += pat;
        return ans;
    }
}
int main(){
    string s;
    cin >> s;
    while(1){
        if(count(s.begin(), s.end(), '[') == 0 && count(s.begin(), s.end(), ']') == 0){
            cout << s;
            return 0;
        }
        while(1){
            int start = -1, end = -1, now = 0;
            string ans = "";
            now = end + 1;
            start = (int)s.find('[', now);
            if(start == -1){
                ans += s.substr(now);
                break;
            }
            ans += GetAns(s.substr(now, start - now));
            for(int i = start + 1; i < s.size(); i++){
                string pat = s.substr(start, i - start + 1);
                if(count(pat.begin(), pat.end(), '[') == count(pat.begin(), pat.end(), ']')){
                    ans += GetAns(pat);
                    end = i;
                    break;
                }
            }
            s = ans;
        }
    }
}