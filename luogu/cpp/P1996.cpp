#include<iostream>
#include<vector>
using namespace std;
struct person{
    int id,num;
};
vector<person> p;
int n,m;
int main(){
    cin>>n>>m;
    int quantity=n;
    for(int i=1;i<=n;i++)
        p.push_back({i,i%m});
    while(quantity>0){
        int end=p[quantity-1].num;
        for(int i=0;i<quantity;i++){
            if(p[i].num==0){
                //out.push_back(p[i]);
                cout<<p[i].id<<" ";
                p.erase(p.begin()+i);
                quantity--;
                i--;
            }
        }
        p[0].num=(end+1)%m;
        for(int i=1;i<quantity;i++)
            p[i].num=(p[i-1].num+1)%m;
    }
    /*for(int i=0;i<out.size();i++)
        cout<<out[i].id<<" ";*/
    return 0;
}