#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> p(n+1);
    int pos=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(p[i]==x) pos=i;
    }
    
    int l=1,r=n+1;
    while(r-l>1){
        int m=(l+r)/2;
        if(p[m]<=x) l=m;
        else r=m;
    }
    
    if(l==pos){
        cout<<0<<'\n';
    }else{
        cout<<1<<'\n';
        cout<<l<<" "<<pos<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    
    while(t--) solve();
    //system("pause");
    return 0;
}