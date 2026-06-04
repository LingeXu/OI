#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

string s1,s2;

vector<int> a,b;

long long B;

vector<int> div(vector<int> a,vector<int> b){
    vector<int> c;
    long long now=0;

    for(int i=0;i<s1.size();i++)
    {
        now=now*10+(s1[i]-'0');

        if(now<B)
            c.push_back(0);

        else
        {
            c.push_back(now/B);
            now=now%B;
        }
    }

    int start=0;
    while(c[start]==0&&start<c.size()-1){
        start++;
    }

    return vector<int> (c.begin()+start,c.end());
}

int main(){
    cin>>s1>>s2;

    for(int i=0;i<s1.size();i++)
        a.push_back(s1[i]-'0');

    for(int i=0;i<s2.size();i++)
        b.push_back(s2[i]-'0');

    B=0;
    for(int i=0;i<s2.size();i++)
    {
        /*cout<<s2[i]<<endl;
        cout<<pow(10,s2.size()-i-1)<<endl;
        cout<<B<<endl;*/

        B=B+(s2[i]-'0')*(int)(pow(10,s2.size()-i-1));

        //cout<<B<<endl;
    }


    vector<int> C=div(a,b);

    for(int i=0;i<C.size();i++)
        printf("%d",C[i]);

    return 0;
}