#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> a,b;

vector<int> add(vector<int> &a,vector<int> &b){
    vector<int> c;
    int carry=0;

    for(int i=0;i<max(a.size(),b.size())||carry;i++)
    {
        if(i<a.size())
            carry+=a[i];

        if(i<b.size())
            carry+=b[i];

        c.push_back(carry%10);

        carry/=10;
    }

    return c;
}

int main(){
    /*for(int i=a.size()-1;i>=0;i--)
        scanf("%d",&a[i]);

    for(int i=b.size()-1;i>=0;i--)
        scanf("%d",&b[i]);*/

    string s1,s2;
    cin>>s1>>s2;

    for(int i=s1.size()-1;i>=0;i--)
        a.push_back(s1[i]-'0');
    
    for(int i=s2.size()-1;i>=0;i--)
        b.push_back(s2[i]-'0');

    vector<int> c=add(a,b);

    for(int i=c.size()-1;i>=0;i--)
        printf("%d",c[i]);

    return 0;
}