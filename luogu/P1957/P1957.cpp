#include<iostream>
#include<vector>

#define N 51

using namespace std;

int n;
vector<string> s;

int main(){
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++)
    {
        string line;
        getline(cin,line);
        s.push_back(line);
    }

    char last;

    for(int i=0;i<n;i++)
    {   
        int fi=0,se=0,beg;
        string formula;

        if(!(s[i][0]>='0'&&s[i][0]<='9'))
        {
            for(int j=2;j<s[i].size()-1;j++)
            {
                if(s[i][j]>='0'&&s[i][j]<='9')
                    fi=fi*10+(s[i][j]-'0');
                
                else 
                {
                    beg=j+1;
                    break;
                }
            }

            for(int k=beg;k<s[i].size();k++)
            {
                if(s[i][k]>='0'&&s[i][k]<='9')
                    se=se*10+(s[i][k]-'0');
                
                else    break;
            }

            if(s[i][0]=='a')
            {
                last='+'; 
                formula=to_string(fi)+"+"+to_string(se)+"="+to_string(fi+se);
                cout<<formula<<endl;
                cout<<formula.size()<<endl;
            }

            else if(s[i][0]=='b')
            {
                last='-';
                formula=to_string(fi)+"-"+to_string(se)+"="+to_string(fi-se);
                cout<<formula<<endl;
                cout<<formula.size()<<endl;
            }
                

            else if(s[i][0]=='c')
            {
                last='*';
                formula=to_string(fi)+"*"+to_string(se)+"="+to_string(fi*se);
                cout<<formula<<endl;
                cout<<formula.size()<<endl;
            }     
        }

        else
        {
            for(int j=0;j<s[i].size()-1;j++)
            {
                if(s[i][j]>='0'&&s[i][j]<='9')
                    fi=fi*10+s[i][j]-'0';

                else 
                {
                    beg=j+1;
                    break;
                }
            }

            for(int k=beg;k<s[i].size();k++)
            {
                if(s[i][k]>='0'&&s[i][k]<='9')
                    se=se*10+s[i][k]-'0';

                else    break;
            }

            if(last=='+') 
            {
                formula=to_string(fi)+"+"+to_string(se)+"="+to_string(fi+se);
                cout<<formula<<endl;
                cout<<formula.size()<<endl;
            }  
            else if(last=='-')
            {
                formula=to_string(fi)+"-"+to_string(se)+"="+to_string(fi-se);
                cout<<formula<<endl;
                cout<<formula.size()<<endl;
            }   
            else if(last=='*')
            {
                formula=to_string(fi)+"*"+to_string(se)+"="+to_string(fi*se);
                cout<<formula<<endl;
                cout<<formula.size()<<endl;
            }   
        }
    }

    return 0;
}