#include<iostream>
#include<vector>

using namespace std;

string s1,s2;
vector<int> a,b,ans;

vector<int> mul(vector<int> a,vector<int> b){
    vector<int> c(a.size()+b.size(),0);

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            c[i+j]+=a[i]*b[j];
        }
    }

    for(int i=0;i<c.size()-1;i++)
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }

    c.push_back(c.back()/10);
    c[c.size()-2]=c[c.size()-2]%10;

    while(c.back()==0&&c.size()>1){
        c.pop_back();
    }

    return c;
}

int main(){
    cin>>s1>>s2;

    for(int i=s1.size()-1;i>=0;i--)
        a.push_back(s1[i]-'0');

    for(int i=s2.size()-1;i>=0;i--)
        b.push_back(s2[i]-'0');  

    ans=mul(a,b);

    for(int i=ans.size()-1;i>=0;i--)
        printf("%d",ans[i]);
    
    return 0;
}