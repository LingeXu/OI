#include<iostream>

using namespace std;

int n;
string s;

int main(){
    cin>>n;
    cin.ignore();
    cin>>s;

    string pat="VK";
    int cnt=0,last=0;;

    while(1){
        int ans=(int)s.find(pat,last);
        if(ans==-1)
            break;

        cnt++;

        last=ans+pat.size(); 
        if(last>=s.size())
            break;
    }

    if(s[0]=='K'&&s[1]=='K')
    {
        cout<<cnt+1;
        return 0;
    }

    else if(s[s.size()-2]=='V'&&s[s.size()-1]=='V')
    {
        cout<<cnt+1;
        return 0;
    }  
    
    else
    {
        string pat1="VVV",pat2="KKK";

        if((int)s.find(pat1)!=-1||(int)s.find(pat2)!=-1)
        {
            cout<<cnt+1;
            return 0;
        }

        else
        {
            cout<<cnt;
            return 0;
        }
    }

    return 0;
}