#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>

using namespace std;

string ob,pat;

int main(){
    getline(cin,pat);
    getline(cin,ob);

    for(int i=0;i<pat.size();i++)
        if(pat[i]>='A'&&pat[i]<='Z')
            pat[i]=tolower(pat[i]);
    for(int i=0;i<ob.size();i++)
        if(ob[i]>='A'&&ob[i]<='Z')
            ob[i]=tolower(ob[i]);

    pat=" "+pat+" ",ob=" "+ob+" ";

    int cnt=0,pos=0,ans;

    //if((int)ob.find(pat)!=-1)    ans=(int)ob.find(pat);

    while(1){
        int now=(int)ob.find(pat,pos);
        if(now==-1)
            break;

        if(cnt==0)
            ans=now;

        cnt++;

        pos=now+pat.size()-2;
    }

    if(cnt!=0)
        cout<<cnt<<" "<<ans;

    else    cout<<-1;

    return 0;
}