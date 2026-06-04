#include<iostream>

using namespace std;

int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;

    string s;
    cin>>s;
    string ans(s);

    int pos=0;
    if(p1==3){
        while(1){
            pos=(int)s.find("-",pos);
            //cout<<"this is pos:"<<pos<<endl;
            if(pos!=-1){
                char front=s[pos-1],rear=s[pos+1];
                if((front>='0'&&rear<='9'&&front<rear)||(front>='a'&&rear<='z'&&front<rear)||(front>='A'&&rear<='Z'&&front<rear)){
                    int cnt=rear-front-1;
                    //cout<<"this is cnt:"<<cnt<<endl;

                    int now=ans.find("-");
                    ans.erase(now,1);
                    while(cnt>0){
                        for(int i=1;i<=p2;i++)
                            ans.insert(now,"*");                         
                        cnt--;
                    }
                }
                
                pos++;
            }

            else    break;
        }
    }
    
    else if(p1==1){
        if(p3==1){
            while(1){
                pos=(int)s.find("-",pos);
                if(pos!=-1){
                    char front=s[pos-1],rear=s[pos+1];
                    if((front>='0'&&rear<='9'&&front<rear)||(front>='a'&&rear<='z'&&front<rear)){
                        int cnt=rear-front-1;
                        cout<<front<<" "<<rear<<" "<<cnt<<endl;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,1,ans[now+i-1]-1);                         
                            cnt--;
                        }
                    }
                    /*else if(front>='a'&&rear<='z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,to_string(ans[now]-'1'));                         
                            cnt--;
                        }
                    }*/
                    else if(front>='A'&&rear<='Z'&&front<rear){
                        int cnt=rear-front-1;
                        cout<<front<<" "<<rear<<" "<<cnt<<endl;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,1,tolower(ans[now+i-1]-1));                         
                            cnt--;
                        }
                    }

                    else if(front==rear){cout<<front<<" "<<rear<<endl;};

                    pos++;
                }

                else    break;
            }
        }
        else if(p3==2){
            while(1){
                pos=(int)s.find("-",pos);
                if(pos!=-1){
                    char front=s[pos-1],rear=s[pos+1];
                    if((front>='0'&&rear<='9'&&front<rear)||(front>='a'&&rear<='z'&&front<rear)){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++){
                                if(cnt==rear-front-1){
                                    ans.insert(now,1,ans[now-1]+1);
                                    //cout<<ans<<endl;
                                }
                                else                                   
                                    ans.insert(now,1,ans[now+i-1]+1);    
                            }                     
                            cnt--;
                        }
                    }
                    /*else if(front>='a'&&rear<='z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,to_string(ans[now]-'1'));                         
                            cnt--;
                        }
                    }*/
                    else if(front>='A'&&rear<='Z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                if(cnt==rear-front-1)
                                    ans.insert(now,1,tolower(ans[now-1]+1));
                                else
                                    ans.insert(now,1,tolower(ans[now+i-1]+1));                         
                            cnt--;
                        }
                    }

                    pos++;
                }

                else    break;
            }
        }
    }

    else if(p1==2){
        if(p3==1){
            while(1){
                pos=(int)s.find("-",pos);
                if(pos!=-1){
                    char front=s[pos-1],rear=s[pos+1];
                    if((front>='0'&&rear<='9'&&front<rear)||(front>='A'&&rear<='Z'&&front<rear)){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,1,ans[now+i-1]-1);                         
                            cnt--;
                        }
                    }
                    /*else if(front>='a'&&rear<='z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,to_string(ans[now]-'1'));                         
                            cnt--;
                        }
                    }*/
                    else if(front>='a'&&rear<='z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,1,toupper(ans[now+i-1]-1));                         
                            cnt--;
                        }
                    }

                    pos++;
                }

                else    break;
            }
        }
        else if(p3==2){
            while(1){
                pos=(int)s.find("-",pos);
                if(pos!=-1){
                    char front=s[pos-1],rear=s[pos+1];
                    if((front>='0'&&rear<='9'&&front<rear)||(front>='A'&&rear<='Z'&&front<rear)){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                if(cnt==rear-front-1)
                                    ans.insert(now,1,ans[now-1]+1);  
                                else                                   
                                    ans.insert(now,1,ans[now+i-1]+1);                         
                            cnt--;
                        }
                    }
                    /*else if(front>='a'&&rear<='z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                ans.insert(now,to_string(ans[now]-'1'));                         
                            cnt--;
                        }
                    }*/
                    else if(front>='a'&&rear<='z'&&front<rear){
                        int cnt=rear-front-1;
                        int now=ans.find("-");
                        ans.erase(now,1);
                        //cout<<ans<<endl;
                        while(cnt>0){
                            for(int i=1;i<=p2;i++)
                                if(cnt==rear-front-1){
                                    ans.insert(now,1,toupper(ans[now-1]+1));
                                    //cout<<ans<<endl;
                                }

                                else{
                                    ans.insert(now,1,toupper(ans[now+i-1]+1));     
                                    //cout<<ans<<endl;  
                                }
                            cnt--;
                        }
                    }
                    
                    pos++;
                }

                else    break;
            }
        }
    }

    cout<<ans;

    return 0;
}