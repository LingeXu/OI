#include<iostream>

using namespace std;

int cnt[10]={0};

int main(){
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        cnt[s[i]-'0']++;
    }

    for(int i=0;i<=9;i++)
        if(cnt[i]!=0)
            printf("%d:%d\n",i,cnt[i]);

    return 0;
}