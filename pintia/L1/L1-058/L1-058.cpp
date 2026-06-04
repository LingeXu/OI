#include<iostream>

using namespace std;

int main(){
    string s;
    getline(cin,s);

    string ans(s);

    for(int i=0;i<s.size();i++){
        int cnt=0,now=i;
        while(i<s.size()&&s[i]=='6'){
            cnt++;
            i++;
        }

        if(cnt>9){
            s.erase(now,cnt);
            s.insert(now,"27");
            i=i-cnt+1;
        }

        else if(cnt>3&&cnt<=9){
            s.erase(now,cnt);
            s.insert(now,"9");
            i=i-cnt;
        }
    }

    cout<<s;

    return 0;
}