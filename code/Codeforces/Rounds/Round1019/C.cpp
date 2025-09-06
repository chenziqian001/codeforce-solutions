#include<bits/stdc++.h>
using namespace std;
int n,k;
void solve(){
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<=k) a[i]=1;
        else a[i]=-1;
    }
    vector<int> pre(n+1),suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=n;i>0;i--) suf[i]=suf[i+1]+a[i];
    vector<int> msp(n+2,-n);
    for(int i=n;i>=1;i--){
        msp[i]=max(msp[i+1],pre[i]);
    }

    for(int i=1;i<=n-2;i++){
        if(pre[i]>=0 && msp[i+1]>=pre[i]){
            cout<<"YES"<<'\n';
            return;
        }
    }


    vector<int> mps(n+1,-n);
    for(int i=1;i<=n;i++){
        mps[i]=max(mps[i-1],suf[i]);
    }
    for(int i=n;i>2;i--){
        if(suf[i]>=0 && mps[i-1]>=suf[i]){
            cout<<"YES"<<'\n';
            return;
        }
    }
    int l=1;
    while(l<=n && pre[l]<0) l++;
    int r=n;
    while(r>=1 && suf[r]<0) r--;
    if(l+2<=r) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}