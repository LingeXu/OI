#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE__<<']'<<" "<<#x<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<algorithm>
#include<iomanip>
#define N 210
using namespace std;
struct coffee{
    int v,c;
    double val;
};
vector<coffee> cof(N);
bool cmp(coffee x,coffee y){
    return x.val>y.val;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>cof[i].v;
    for(int i=0;i<n;i++)    cin>>cof[i].c;   
    for(int i=0;i<n;i++)    cof[i].val=1.0*cof[i].v/cof[i].c;  
    int sum_v=0,sum_c=0;
    int now_v,now_c;
    coffee now;
    double now_val,max_val=0;
    int record_v=0,record_c=0;
    vector<coffee>::iterator it,chosen;
    while(m>0){
        for(it=cof.begin();it!=cof.end();it++){
            now_v=sum_v,now_c=sum_c;
            now=*it;
            now_v+=now.v,now_c+=now.c;
            now_val=1.0*now_v/now_c;
            if(now_val>max_val||(now_val==max_val&&now.v>record_v)){
                max_val=now_val;
                record_v=now.v,record_c=now.c;
                chosen=it;
            }
        }
        sum_v+=record_v,sum_c+=record_c;
        debug(sum_v);
        debug(sum_c);
        debug(chosen-cof.begin());
        cof.erase(chosen);
        m--;
    }
    double ans=1.0*sum_v/sum_c;
    //printf("%.3f\n",ans);
    cout<<fixed<<setprecision(3)<<ans;
    return 0;
}