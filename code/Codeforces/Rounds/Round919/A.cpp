#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> no;
    int l=1;
    int r=1e9+1;


    while(n--){
        int a,x;
        cin>>a>>x;
        if(a==1){
            l=max(l,x);
        }
        else if(a==2){
            r=min(r,x);
        }
        else{
            no.push_back(x);
        }
    }


    int res=r-l+1;
    for(int x:no){
        if(x>=l && x<=r){
            res--;
        }
    }
    cout<<max(res,0LL)<<'\n';
    





    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
