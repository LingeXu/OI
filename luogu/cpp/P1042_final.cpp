#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> board;
int a[2]={11,21};

int main(){
    char c;
    while(1){
        c=getchar();
        if(c=='E')
            break;
        if(c=='W')  board.push_back(1);
        else if(c=='L')
            board.push_back(-1);

        /*for(int i=0;i<2;i++){
            int sum=0;
            for(int j=0;j<board.size();j++){
                sum+=board[j];

                if(sum==a[i]){
                    cout<<a[i]<<':'<<j+1-a[i];
                    printf("\n");
                    sum=0;
                }
            }
            printf("\n");
        }*/
    }

    if(board.size()==0){
        cout<<"0:0";
        printf("\n");
        printf("\n");
        cout<<"0:0";
        return 0;
    }
    for(int i=0;i<2;i++){
        int sum1=0,sum2=0;
        if(i==1)
            printf("\n");
        for(int j=0;j<board.size();j++){
            if(board[j]==1)
                sum1++;
            else if(board[j]==-1)
                sum2++;

            if(j==board.size()-1){
                cout<<sum1<<':'<<sum2;
                printf("\n");
                if((sum1>=a[i]&&sum1-sum2>=2)||(sum2>=a[i]&&sum2-sum1>=2)){
                    cout<<"0:0";
                    printf("\n");
                }
                break;
            }
            
            if(sum1>=a[i]&&sum1-sum2>=2){
                cout<<sum1<<':'<<sum2;
                printf("\n");
                sum1=sum2=0;
                continue;
            }

            else if(sum2>=a[i]&&sum2-sum1>=2){
                cout<<sum1<<':'<<sum2;
                printf("\n");
                sum1=sum2=0;
                continue;
            }
        }
    }

    return 0;
}