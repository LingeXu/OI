#include<iostream>
#include<algorithm>

using namespace std;

int score1=0,score2=0;
int a[2]={11,21};

int main(){
    int now=0;

    while(1){
        char c;
        c=getchar();

        if(c=='E'){
            int sc1=score1,sc2=score2;
            if(sc1<sc2){
                swap(sc1,sc2);
                cout<<sc2<<" "<<sc1<<endl;
                cout<<endl;
            }

            break;
        }

        if(c=='W')
            score1++;

        else if(c=='L')
            score2++;

        if(score1==11){
            cout<<11<<':'<<score2<<endl;
            score1=score2=0;
        }

        else if(score2==11){
            cout<<11<<':'<<score1<<endl;
            score1=score2=0;
        }

    }

    return 0;
}