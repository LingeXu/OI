#include<iostream>

using namespace std;

int q;
string s;

int main(){
    cin>>q;
    cin.ignore();
    cin>>s;
    cin.ignore();
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        
        if(x==1)
        {
            string op;
            cin>>op;

            s.append(op);
        }

        else if(x==2)
        {
            int st,leng;
            cin>>st>>leng;

            s=s.substr(st,leng);
        }

        else if(x==3)
        {
            int st;
            string op;
            cin>>st>>op;

            s.insert(st,op);
        }

        else if(x==4)
        {
            string op;
            cin>>op;

            cout<<(int)s.find(op)<<endl;

            continue;
        }

        cout<<s<<endl;
    }
}