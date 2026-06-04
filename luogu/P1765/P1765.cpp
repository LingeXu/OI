#include<iostream>

using namespace std;

int main(){
    string s;
    getline(cin,s);

    int cnt=0;

    for(int i=0;i<s.size();i++)
    {
        char c=s[i];

        if(c==' ')
            cnt++;

        if(c>='a'&&c<='o')
            cnt+=((c-'a')%3+1);

        if(c=='p'||c=='t'||c=='w')
            cnt++;
            
        if(c=='q'||c=='u'||c=='x')
            cnt+=2;

        if(c=='r'||c=='v'||c=='y')
            cnt+=3;

        if(c=='s'||c=='z')
            cnt+=4;
    }

    cout<<cnt;

    return 0;
}