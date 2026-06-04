#include<iostream>

using namespace std;

string s1,s2,s3,s4;
int cnt[26]={0};

int main(){
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    getline(cin,s4);

    for(int i=0;i<s1.size();i++)
        if(s1[i]>='A'&&s1[i]<='Z')
            cnt[s1[i]-'A']++;
    
    for(int i=0;i<s2.size();i++)
        if(s2[i]>='A'&&s2[i]<='Z')
            cnt[s2[i]-'A']++;

    for(int i=0;i<s3.size();i++)
        if(s3[i]>='A'&&s3[i]<='Z')
            cnt[s3[i]-'A']++;

    for(int i=0;i<s4.size();i++)
        if(s4[i]>='A'&&s4[i]<='Z')
            cnt[s4[i]-'A']++;

    /*for(int i=0;i<26;i++)
        cout<<cnt[i]<<" ";*/

    int maxcnt=0;

    for(int i=0;i<26;i++)
        if(cnt[i]>maxcnt)
            maxcnt=cnt[i];

    for(int i=0;i<maxcnt;i++){
        for(int j=0;j<26;j++){
            if(cnt[j]<maxcnt-i)
                cout<<" ";

            else    cout<<"*";

            if(j!=25)
                cout<<" ";
        }
        cout<<endl;
    }

    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

    return 0;
}