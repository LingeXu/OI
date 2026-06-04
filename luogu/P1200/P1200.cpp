#include<iostream>
#include<cmath>

using namespace std;

string s1,s2;

int main(){
    cin>>s1>>s2;

    int ans1 = 1 , ans2 = 1;
    for(int i = 0; i < s1.size(); i++)
        ans1*=(s1[i]-'A'+1);

    for(int i = 0; i < s2.size(); i++)
        ans2*=(s2[i]-'A'+1);

    if(abs(ans1-ans2)%47==0)
        cout<<"GO";
    else    cout<<"STAY";
    
    return 0;
}