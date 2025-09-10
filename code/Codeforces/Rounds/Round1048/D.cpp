#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> li(n+1,0);
    vector<int> ri(n+2,n+1);
    for(int i=1;i<=n;i++){
        li[i]=i-1;
        while(li[i]>0 && a[i]>a[li[i]]){
            li[i]=li[li[i]];
        }
    }
    for(int i=n;i>=1;i--){
        ri[i]=i+1;
        while(ri[i]<n+1 && a[i]<a[ri[i]]){
            ri[i]=ri[ri[i]];
        }
    }
    vector<int> mR(n+2,n+1);
    for(int i=1;i<=n;i++){
        if(li[i] && ri[i]!=n+1){
            mR[li[i]]=min(mR[li[i]],ri[i]);
        }
    }

    for(int i=n-1;i>=1;i--){
        mR[i]=min(mR[i],mR[i+1]);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(mR[l]<=r){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}