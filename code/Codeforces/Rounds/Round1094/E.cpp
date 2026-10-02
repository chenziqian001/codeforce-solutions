#include<bits/stdc++.h>
using namespace std;
#define int long long

int ins(int x){
    cout<<"I "<<x<<endl;
    int res;
    cin>>res;
    if(res==-1) exit(0);
    return res;
}

int ask(int x){
    cout<<"Q "<<x<<endl;
    int res;
    cin>>res;
    if(res==-1) exit(0);
    return res;
}

void solve(){
    int n;
    if(!(cin>>n)) return;
    cout<<0<<endl;
    
    int k=0,c=0;
    int sz=ins(0);
    if(sz==1){
        k=1;
        sz=ins((1LL<<n)-1);
    }
    
    for(int i=n-1;i>=0;i--){
        int mid=c|(1LL<<i);
        int cnt=ask(mid);
        if(cnt>=1){
            c=mid;
        }
    }
    
    if(k==1){
        cout<<"A "<<k<<" "<<c<<endl;
        return;
    }
    
    if((c&(c-1))!=0){
        int lb=c&-c;
        sz=ins(lb);
        if(sz==2) k=2;
        else k=3;
    }else{
        int mx=(1LL<<n)-1;
        sz=ins(mx);
        int cnt=ask(mx);
        if(cnt==1) k=2;
        else k=3;
    }
    cout<<"A "<<k<<" "<<c<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}