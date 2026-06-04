#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();

    while(n>0){
        string s;
        getline(cin,s);

        cout<<s;
        printf("\n");//打印原话

        string ans;

        printf("AI: ");//前缀

        for(int i=0;i<(int)s.size();i++)
            if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I')
                s[i]=tolower(s[i]);//转小写
        
        for(int i=0;i<(int)s.size();i++){
            if(s[i]==' '){
                if(i==0||i==(int)s.size()-1){
                    s.erase(i,1);
                    i--;
                }

                else{
                    if(!(s[i-1]!=' '&&((s[i+1]>='0'&&s[i+1]<='9')||(s[i+1]>='a'&&s[i+1]<='z')))){
                        s.erase(i,1);
                        i--;
                    }
                }
            }
        }//删空格

        for(int i=0;i<(int)s.size();i++)
            if(s[i]=='?')
                s[i]='!';//将？改为！

        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='I'&&((i==0&&s[1]==' ')||(i==s.size()-1&&s[i-1]==' ')||(i!=0&&i!=s.size()-1&&s[i-1]==' '&&s[i+1]==' '))){
                s.erase(i,1);
                s.insert(i,"you");
                i+=2;
            }
        }//将I改为you

        for(int i=0;i<(int)s.size();i++){
            if(i+1<(int)s.size()&&s[i]=='m'&&s[i+1]=='e'){
                s.erase(i,2);
                s.insert(i,"you");
                i+=2;
            }
        }//将me改为you

        for(int i=0;i<(int)s.size();i++){
            if(i+6<(int)s.size()&&s[i]=='c'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]==' '&&s[i+4]=='y'&&s[i+5]=='o'&&s[i+6]=='u'){
                s.erase(i,7);
                //cout<<s<<endl;
                s.insert(i,"I can");
                //cout<<s<<endl;
                i+=4;
            }
        }//将can you改为I can

        for(int i=0;i<(int)s.size();i++){
            if(i+8<(int)s.size()&&s[i]=='c'&&s[i+1]=='o'&&s[i+2]=='u'&&s[i+3]=='l'&&s[i+4]=='d'&&s[i+5]==' '&&s[i+6]=='y'&&s[i+7]=='o'&&s[i+8]=='u'){
                s.erase(i,9);
                s.insert(i,"I could");
                i+=6;
            }
        }//将could you改为I could

        cout<<s<<endl;

        n--;
    }

    return 0;

    
}