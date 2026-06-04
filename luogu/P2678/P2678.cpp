#include<iostream>
#include<vector>

#define N 50001
#define INF 0x3f3f3f3f

using namespace std;

int l,n,m;
int d[N],s[N];

vector<int> del(vector<int> s){
    vector<int> a;
    int b,c;
    int m=INF;
    for(int i=0;i<s.size();i++)
        if(s[i]<m)
            m=s[i];

    for(int i=0;i<s.size();i++)
    {
        if(s[i]==m&&i==0)
            b=c=0;   
        
        if(s[i]==m&&i==s.size()-1)
            b=c=s.size()-1; 

        if(s[i]==m&&i!=0&&i!=s.size()-1&&s[i-1]>=s[i+1])
            b=i,c=i+1;

        if(s[i]==m&&i!=0&&i!=s.size()-1&&s[i-1]<s[i+1])
            b=i,c=i-1;
    }

    for(int i=0;i<s.size();i++)
        if(i!=b&&i!=c)
            a.push_back(s[i]);

    return a;
}

int main(){
    vector<int> s;
    cin>>l>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];

        if(i==0)    s.push_back(d[0]);
        else    s.push_back(d[i]-d[i-1]);
    }

    s.push_back(l-d[n-1]);

    while(m>0){
        s=del(s);
        m--;
    }

    //cout<<del(s);
    int m=INF;
    for(int i=0;i<s.size();i++)
        if(s[i]<m)
            m=s[i];

    cout<<m;

    return 0;
}