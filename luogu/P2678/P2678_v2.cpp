#include<iostream>

#define N 50001

using namespace std;

int l,m,n;
int d[N],s[N+1];

int main(){
    cin>>l>>m>>n;
    if(m==0) 
    {
        cout<<l;
        return 0;
    }
        
    
    for(int i=0;i<m;i++)   
    {
        cin>>d[i];

        if(i==0)    s[0]=d[0];
        else    s[i]=d[i]-d[i-1];
    }
    s[m]=l-d[m-1];

    /*for(int i=0;i<=m;i++)
        cout<<s[i]<<" ";*/

    int head=0,tail=l,mid;
    while(head<tail){
        int cnt=0;

        for(int i=0;i<m+1;i++)
        {
            /*while(i<m&&s[i-cnt]<mid)
            {
                s[i-cnt]+=s[i+1];
                i++;
                cnt++;
                ans++;
            }*/
            mid=(head+tail)/2;
            while(mid-s[i]>0&&i<m+1){
                mid-=s[i];
                i++;
                cnt++;
            }
        }

        mid=(head+tail)/2;

        if(cnt>n) 
        {
            //cout<<"Hello"<<endl;
            tail=mid-1; 
            //cout<<head<<" "<<tail<<endl;
        } 

        else if(cnt<n) 
        {
            //cout<<"Hi"<<endl;
            head=mid+1;
            //cout<<head<<" "<<tail<<endl;
        } 

        else 
        {
            //cout<<"!"<<endl;
            cout<<mid<<endl;
            return 0;
        }   
    }

    cout<<head;

    return 0;
}