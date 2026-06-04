#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore(); 

    char s;
    while(1){
        s=getchar();
        
        if(s!=EOF)
            putchar((s-'a'+n)%26+'a');
        
        else    break;
    }

    return 0;
}