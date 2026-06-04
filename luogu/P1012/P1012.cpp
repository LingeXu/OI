#include<iostream>
#include<algorithm>
#define N 30
using namespace std;
vector<string> z;
bool cmp(string s1,string s2){
    return s1+s2>s2+s1;
}
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        z.push_back(s);
    }
    sort(z.begin(),z.end(),cmp);
    for(int i=0;i<n;i++)    cout<<z[i];
    return 0;
}