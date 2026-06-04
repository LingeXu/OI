#include<iostream>

#define TIME 10000

using namespace std;

struct status{
    int x,y;
    char now;//'N','E','S','W'
}farmer,cows;

bool is_available[12][12]={0};

int main(){
    string s;
    int ti=0;
    int cnt=10;
    while(cnt>0){
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'||s[i]=='F'||s[i]=='C')
                is_available[11-cnt][i+1]=true;
            if(s[i]=='F')
                farmer.x=11-cnt,farmer.y=i+1;
            if(s[i]=='C')
                cows.x=11-cnt,cows.y=i+1;
        }

        cnt--;
    }
    farmer.now=cows.now='N';

    while(1){
        if(ti>TIME){
            cout<<0;
            return 0;
        }
        if(farmer.x==cows.x&&farmer.y==cows.y){
            cout<<ti;
            return 0;
        }
        for(int i=1;i<=2;i++){
            if(i==1){
                if(farmer.now=='N'){
                    farmer.x--;
                    if(!is_available[farmer.x][farmer.y]){
                        farmer.x++;
                        farmer.now='E';
                    }
                    continue;
                }

                if(farmer.now=='E'){
                    farmer.y++;
                    if(!is_available[farmer.x][farmer.y]){
                        farmer.y--;
                        farmer.now='S';
                    }
                    continue;
                }       
        
                if(farmer.now=='S'){
                    farmer.x++;
                    if(!is_available[farmer.x][farmer.y]){
                        farmer.x--;
                        farmer.now='W';
                    }
                    continue;
                }

                if(farmer.now=='W'){
                    farmer.y--;
                    if(!is_available[farmer.x][farmer.y]){
                        farmer.y++;
                        farmer.now='N';
                    }
                    continue;
                }
            }

            else if(i==2){
                if(cows.now=='N'){
                    cows.x--;
                    if(!is_available[cows.x][cows.y]){
                        cows.x++;
                        cows.now='E';
                    }
                    continue;
                }

                if(cows.now=='E'){
                    cows.y++;
                    if(!is_available[cows.x][cows.y]){
                        cows.y--;
                        cows.now='S';
                    }
                    continue;
                }       
        
                if(cows.now=='S'){
                    cows.x++;
                    if(!is_available[cows.x][cows.y]){
                        cows.x--;
                        cows.now='W';
                    }
                    continue;
                }

                if(cows.now=='W'){
                    cows.y--;
                    if(!is_available[cows.x][cows.y]){
                        cows.y++;
                        cows.now='N';
                    }
                    continue;
                }
            }
            
        }
        ti++;
    }

    //cout<<ti;
    return 0;
}