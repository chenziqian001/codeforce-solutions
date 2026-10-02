#include<bits/stdc++.h>
using namespace std;
#define int long long
char ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    char res;
    cin>>res;
    return res;
}
void ans(int a,int b){
    cout<<"! "<<a<<" "<<b<<endl;
}

void solve(){
    int n;
    cin>>n;
    int mini,maxi;
    int st;
    if(n%2==1){
        mini=maxi=1;
        st=2;
    }
    else{
        char res=ask(1,2);
        if(res=='<'){mini=1;maxi=2;}
        else if(res=='>'){mini=2;maxi=1;}
        else mini=maxi=1;
        st=3;
    }
    for(int i=st;i<=n;i+=2){
        char q=ask(i,i+1);
        int x,y;
        if(q=='<'){
            x=i,y=i+1;
        }  
        else if(q=='>'){
            x=i+1,y=i;
        }
        else{
            x=y=i;
        }
        if(ask(x,mini)=='<') mini=x;
        if(ask(y,maxi)=='>') maxi=y;
    }
    ans(mini,maxi);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}