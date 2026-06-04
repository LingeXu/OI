#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int cnt[26];

void isPrime(int &x){
    if(x==0||x==1)
    {
        cout<<"No Answer"<<endl;
        x=0;
        return;
    }    
    if(x==2)   
    {
        cout<<"Lucky Word"<<endl;
        return;
    } 

    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            cout<<"No Answer"<<endl;
            x=0;
            return;
        }       
    }
        
    cout<<"Lucky Word"<<endl;
    return;
}

int main(){
    char c;
    while((c=getchar())!=EOF){
        if(c>='a'&&c<='z')
            cnt[c-'a']++;
    }

    sort(cnt,cnt+26);

    for(int i=0;i<26;i++)
    {
        if(cnt[i]!=0)
        {
            int ans=cnt[25]-cnt[i];
            isPrime(ans);
            cout<<ans;
            return 0;
        }
    }
            
    return 0;
}