#include<iostream>

using namespace std;

int p1,p2,p3;
string expand(char front,char rear){
    if(front>=rear)
        return "-";

    int cnt=rear-front-1;
    string s;

    if(p3==1){
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=p2;j++){
                if(p1==1)   s+=tolower(front+i);
                else if(p1==2)  s+=toupper(front+i);
                else if(p1==3)  s+='*';
            }
        }
    }

    else if(p3==2){
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=p2;j++){
                if(p1==1)   s+=tolower(rear-i);
                else if(p1==2)  s+=toupper(rear-i);
                else if(p1==3)  s+='*';
            }
        }
    }

    return s;
}

int main(){
    cin>>p1>>p2>>p3;

    string s;
    cin>>s;

    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]!='-')
            ans+=s[i];
        else{
            char front=s[i-1],rear=s[i+1];
            if((isdigit(front)&&isdigit(rear))||(islower(front)&&islower(rear))){
                ans+=expand(front,rear);
            }
            else    ans+='-';
        }
    }
        
    cout<<ans;

    return 0;
}