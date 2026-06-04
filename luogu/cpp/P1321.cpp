#include<iostream>

using namespace std;

string s;

int cnt(string pat){
    int ans=0,last=0;
     
    while(1){
        int loc=(int)s.find(pat,last);
        if(loc==-1)
            break;

        ans++;

        last=loc+1;
        if(last>=s.size())
            break;
    }

    return ans;
}

int main(){
    cin>>s;

    int cnt1=0,cnt2=0;

    int ans1=cnt("o")+cnt("bb")+cnt("bg")+cnt("yy")+cnt("ly"),ans2=cnt("i")+cnt("r")+cnt("gb")+cnt("gg")+cnt("yl")+cnt("ll")-cnt("ir");

    cout<<ans1<<endl;
    cout<<ans2;

    return 0;
}