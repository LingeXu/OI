#include<iostream>
#include<vector>

using namespace std;

int n;

vector<int> add(vector<int> a,vector<int> b){
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

vector<int> mul(vector<int> a,int b){
    vector<int> c;

    int carry=0;

    for(int i=0;i<a.size()||carry;i++)
    {
        if(i<a.size())
            carry+=a[i]*b;

        c.push_back(carry%10);

        carry/=10;
    }

    return c;
}

vector<int> fac(int x){
    vector<int> a;

    if(x==0)    
    {
        a.push_back(1);
        return a;
    }

    return mul(fac(x-1),x);
}

int main(){
    cin>>n;

    vector<int> a={0};

    for(int i=1;i<=n;i++)
        a=add(a,fac(i));

    for(int i=a.size()-1;i>=0;i--)
        printf("%d",a[i]);

    return 0;
}