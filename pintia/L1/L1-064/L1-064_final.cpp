#include<iostream>
#include<vector>

using namespace std;


vector<string> split(string s){
    vector<string> tokens;
    string token;

    for(int i=0;i<(int)s.size();i++){
        bool is_sign=(s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z');
        if(!is_sign){
            if(!token.empty())
                tokens.push_back(token);
            token.clear();
            token+=s[i];
            tokens.push_back(token);
            token.clear();
            continue;
        }
        else if(i==(int)s.size()-1){
            token+=s[i];
            tokens.push_back(token);
        }
        else{
            token+=s[i];
        }
    }

    return tokens;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();

    while(n>0){
        string s;
        getline(cin,s);
        cout<<s;
        printf("\n");//输出原文

        if(s.empty()) {
            cout<<"AI: "<<endl;
            n--;
            continue;
        }

        for(int i=0;i<(int)s.size();i++)
            s[i]=tolower(s[i]);//将大写字母改成小写

        while(1){
            if(s[0]!=' ')   break;
            s.erase(0,1);
        }//删除行首空格

        while(1){
            if(s[s.size()-1]!=' ')  break;
            s.erase(s.size()-1,1);
        }//删除行尾空格

        /*cout<<s;
        printf("\n");*/

        for(int i=1;i<(int)s.size()-1;i++){
            if(s[i]==' '&&!((s[i+1]>='a'&&s[i+1]<='z')||(s[i+1]>='0'&&s[i+1]<='9'))){
                s.erase(i,1);
                i--;
                continue;
            }
        }//删除多余空格

        /*cout<<s;
        printf("\n");*/

        vector<string> tokens=split(s);

        /*for(int i=0;i<(int)tokens.size();i++){
            cout<<tokens[i]<<" "<<"ciallo~"<<endl;
        }*/
        
        for(int i=0;i<(int)tokens.size();i++)
            if(tokens[i]=="?")
                tokens[i]="!";//将？改成！

        for(int i=0;i<(int)tokens.size();i++){
            if(i+2<(int)tokens.size()&&tokens[i]=="can"){
                if(tokens[i+2]=="i"||tokens[i+2]=="me")
                    tokens[i+2]="you";
                else if(tokens[i+2]=="you"){
                    tokens[i]="I";
                    tokens[i+2]="can";
                    i+=2;
                    continue;
                } 
            }
            else if(i+2<(int)tokens.size()&&tokens[i]=="could"){
                if(tokens[i+2]=="i"||tokens[i+2]=="me")
                    tokens[i+2]="you";
                else if(tokens[i+2]=="you"){
                    tokens[i]="I";
                    tokens[i+2]="could";
                    i+=2;
                    continue;
                } 
            }
            else if(tokens[i]=="i"||tokens[i]=="me")
                tokens[i]="you";
        }//替换

        /*cout<<(int)tokens.size();
        printf("\n");
        cout<<tokens[14];*/
        printf("AI: ");
        for(int i=0;i<(int)tokens.size();i++)    cout<<tokens[i];
        printf("\n");

        n--;
    }

    return 0;
   
}