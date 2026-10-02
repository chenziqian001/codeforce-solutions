#include<bits/stdc++.h>
using namespace std;
#define int long long


int ask(int i,int j,int x){
    int res;
    cout<<'?'<<" "<<i<<" "<<j<<" "<<x<<endl;
    cin>>res;
    return res;
}


 
void solve(){
    int n,k;
    cin>>n>>k;
    k=n*n-k+1;
    int l=1,r=n*n;
    int res=r;
    
    auto check=[&](int val)->bool{
        int res=0;
        int i=n,j=1;
        while(i>=1 && j<=n){
            if(ask(i,j,val)){
                res+=i;
                j++;
            }
            else i--;
        }
        return res>=k;
    };
    
    
    
    
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<"! "<<res<<endl;
}
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}
 
 