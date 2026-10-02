#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> cnt1(n+1);
    for(int i=1;i<=n;i++){
        cnt1[i]=(a[i]==1);
    }
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) cnt1[i]+=cnt1[i-1];

    while(q--){
        int l,r;
        cin>>l>>r;
        int len = r-l+1;
        if(len==1){
            cout<<"NO"<<'\n';
            continue;
        }
        int num1=cnt1[r]-cnt1[l-1];
        int sum=s[r]-s[l-1];
        if(sum>=(2*num1+(len-num1))){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }

    
    
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