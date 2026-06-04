#include<iostream>
#include<cstring>
#include<cmath>

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
        string op;
        getline(cin,op);

        if(op[0]=='1')
            for(int j=2;j<op.size();j++)
                s+=op[j];
        
        else if(op[0]=='2')
        {
            string s1=s;
            s.clear();

            int beg=0,length=0;
            for(int j=2;j<op.size();j++)
            {
                if(op[j]>='0'&&op[j]<='9')
                    beg=beg*10+op[j]-'0';

                else    break;
            }

            //cout<<beg<<endl;
            
            for(int k=op.size()-1;k>=0;k--)
            {
                if(op[k]>='0'&&op[k]<='9')
                    length=length+(op[k]-'0')*pow(10,op.size()-1-k);

                else    break;
            }

            //cout<<length<<endl;

            for(int h=beg;h<beg+length;h++)
                s+=s1[h];
        }

        else if(op[0]=='3')
        {
            string s1=s;
            string s2;
            s.clear();


            int loc=0;
            for(int j=2;j<op.size();j++)
            {
                if(op[j]>='0'&&op[j]<='9')
                    loc=loc*10+op[j]-'0';

                else    break;
            }

            for(int k=0;k<loc;k++)
                s+=s1[k];

            for(int h=op.size()-1;h>=0;h--)
            {
                if(op[h]!=' ')
                    s2+=op[h];

                else    break;
            }


            for(int m=s2.size()-1;m>=0;m--)
                s+=s2[m];

            for(int p=loc;p<s1.size();p++)
                s+=s1[p];
        }

        else if(op[0]=='4')
        {
            string s1;
            for(int j=2;j<op.size();j++)
                s1+=op[j];

            //cout<<s1<<endl;

            cout<<(int)s.find(s1)<<endl;
            continue;
        }

        cout<<s<<endl;
    }

    return 0;
}