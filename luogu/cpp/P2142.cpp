#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s1,s2;
vector<int> a,b,c;

bool isGreater(vector<int> a,vector<int> b){
    if(a.size()<b.size()) 
        return 0;

    else if(a.size()>b.size())
        return 1;

    else 
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]>b[i])
                return 1;

            if(a[i]<b[i])
                return 0;
        }

    return 1;
}

vector<int> sub(vector<int> &a,vector<int> &b){
    vector<int> c;
    int carry=0;

    for(int i=0;i<a.size();i++)
    {
        carry+=a[i];

        if(i<b.size())
            carry-=b[i];

        c.push_back((carry+10)%10);

        if(carry>=0)
            carry=0;

        else
            carry=-1;
    }

    while(c.size()>1&&c.back()==0){
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

    if(!isGreater(a,b))
    {
        printf("-");
        swap(a,b);
    }
    
    c=sub(a,b);

    for(int i=c.size()-1;i>=0;i--)
        printf("%d",c[i]);

    return 0;
}