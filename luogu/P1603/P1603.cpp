#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

string s[6];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    for(int i=0;i<6;i++)
        cin>>s[i];

    string pat[27]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};

    int a[6]={0};

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<27;j++)
        if(s[i]==pat[j])
        {
            if(j<=20)
                a[i]=j*j%100;

            else if(j==21)
                a[i]=1;

            else if(j==22)
                a[i]=4;

            else if(j==23)
                a[i]=1;

            else if(j==24)
                a[i]=1;  

            else if(j==25)
                a[i]=4;   

            else if(j==26)
                a[i]=9;                          
        }
    }

    /*for(int i=0;i<6;i++)
        cout<<a[i]<<" ";*/

    sort(a,a+6,cmp);
    
    int pos=0;
    long long ans=0;
    while(1){
        if(a[pos]!=0)
        {
            ans+=a[pos]*pow(100,pos);
            //cout<<ans<<endl;
            pos++;
        }

        else    break;

        if(pos==6)  break;
    }

    cout<<ans;

    return 0;
}