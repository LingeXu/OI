#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    int m=n;

    int cnt=0,ans=0,now,end;
    for(int i=2;i<=sqrt(n);i++){
        now=i,cnt=0;
        while(n%now==0){
            cnt++;
            n/=now;
            now++;
        }
        if(cnt>ans){
            ans=cnt;
            end=now-1;
        }
        n=m;
    }
    if(ans!=0){
        printf("%d\n",ans);
        for(int i=ans;i>1;i--)
            printf("%d*",end-i+1);
        printf("%d",end);
    }
    
    else{
        printf("1\n");
        printf("%d",n);
    }
        
    return 0;
}