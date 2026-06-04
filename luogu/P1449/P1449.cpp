#include<iostream>
#include<stack>

using namespace std;

stack<int> num;

int main(){
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='.')   continue;
        else if(s[i]=='@')  break;
        else if(s[i]=='+'){
            int fi=num.top();
            num.pop();
            int se=num.top();
            num.pop();
            num.push(fi+se);
            //cout<<num.top()<<endl;
        }
        else if(s[i]=='-'){
            int fi=num.top();
            num.pop();
            int se=num.top();
            num.pop();
            num.push(se-fi);
            //cout<<num.top()<<endl;
        }
        else if(s[i]=='*'){
            int fi=num.top();
            num.pop();
            int se=num.top();
            num.pop();
            num.push(fi*se);
            //cout<<num.top()<<endl;
        }
        else if(s[i]=='/'){
            int fi=num.top();
            num.pop();
            int se=num.top();
            num.pop();
            num.push(se/fi);
            //cout<<num.top()<<endl;
        }
        else if(s[i]>='0'&&s[i]<='9'){
            int this_num=s[i]-'0';
            while(1){
                if(s[i+1]>='0'&&s[i+1]<='9'){
                    this_num=this_num*10+s[i+1]-'0';
                    i++;
                }
                else    break;
            }
            num.push(this_num);
        }
    }

    cout<<num.top();

    return 0;
}