#include<iostream>

using namespace std;

string s;
int ans[26]={0};
bool vis[26]={0};

int main(){
    cin>>s;

    int pos=0;
    while(1){
        int pos=(int)s.find(":",pos);
        if(pos==-1)
            break;

        if(s[pos+2]>='0'&&s[pos+2]<='9')
            ans[s[pos-1]-'a']=s[pos+2]-'0';
        else if(s[pos+2]>='a'&&s[pos+2]<='z')
            ans[s[pos-1]-'a']=ans[s[pos+2]-'a'];

        pos++;

        if(pos>=s.size())   break;
    }

    /*for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'&&!vis[s[i]-'a']&&(s[i-1]==';'||i==0)){
            cout<<ans[s[i]-'a']<<" ";
            vis[s[i]-'a']=true;
        }
    }*/

    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];

    return 0;
}