#include<iostream>

using namespace std;

string s;

void reverse(string ob){
    string ans;
    for(int i=ob.size()-1;i>=0;i--)
        ans+=ob[i];

    int start=0;
    while(ans[start]=='0'&&start<ans.size()-1)
        start++;

    ans=ans.substr(start,ans.size()-start);

    cout<<ans;
}

int main(){
    cin>>s;

    int a=(int)s.find('.'),b=(int)s.find('/'),c=(int)s.find('%'),d=s.size();

    if(a==-1&&b==-1&&c==-1)
    {
        reverse(s);
        return 0;
    }

    else if(a!=-1)
    {
        string s1=s.substr(0,a),s2=s.substr(a+1,d-a-1);
        int start=0;
        while(s2[start]=='0'&&start<s2.size()-1)
            start++;
        s2=s2.substr(start,s2.size()-start);

        reverse(s1);
        cout<<".";
        reverse(s2);

        return 0;
    }

    else if(b!=-1)
    {
        string s1=s.substr(0,b),s2=s.substr(b+1,d-a-1);

        reverse(s1);
        cout<<"/";
        reverse(s2);

        return 0;
    }

    else if(c!=-1)
    {
        string s1=s.substr(0,c);

        reverse(s1);
        cout<<"%";

        return 0;
    }

    return 0;
}