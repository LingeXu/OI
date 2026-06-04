#include<iostream>

using namespace std;

int main(){
    char c;
    int cnt=0;
    while((c=getchar())!=EOF){
        if(c!='\n'&&c!=' ')
            cnt++;
    }

    cout<<cnt;
    
    return 0;
}