#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int st=-1,ed=-1;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            st=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            ed=i;
            break;
        }
    }
    if(st==-1){
        cout<<0<<'\n';
        return;
    }
    int res=0;
    for(int i=st;i<ed;i++){
        if(!a[i]) res++;
    }
    cout<<res<<'\n';
    


    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}