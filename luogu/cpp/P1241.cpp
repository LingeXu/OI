#include<iostream>
#include<cstring>
#include<stack>
#define N 110
using namespace std;
stack<int> position;
bool matched[N];
int main(){
    string s;
    cin>>s;
    memset(matched,0,sizeof(matched));
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='[')
            position.push(i);
        else if(s[i]==')'){
            if(!position.empty()){
                int last=position.top();
                if(s[last]=='('){
                    matched[i]=matched[last]=true;
                    position.pop();
                }
            }
        }
        else if(s[i]==']'){
            if(!position.empty()){
                int last=position.top();
                if(s[last]=='['){
                    matched[i]=matched[last]=true;
                    position.pop();
                }
            }
        }
    }
    for(int i=0;i<s.size();i++){
        if(matched[i]==true)
            cout<<s[i];
        else{
            if(s[i]=='('||s[i]==')')
                cout<<"()";
            if(s[i]=='['||s[i]==']')
                cout<<"[]";
        }
    }
    return 0;
}