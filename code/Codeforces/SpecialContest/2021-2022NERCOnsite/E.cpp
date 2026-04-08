#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int l,n;
    cin>>l>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> A(n+1),B(n+1);
    for(int i=1;i<n;i++){
        A[i]=a[i-1];
        B[i]=a[i];
    }
    A[n]=B[n]=l;

    int L=0,R=l,mx=l;
    while(L<=R){
        int mid=(L+R)/2;
        bool ok=true;
        int mini=2e18;
        for(int k=1;k<=n;k++){
            mini=min(mini,B[k-1]-(k-1)*mid);
            if(A[k]-k*mid>mini){
                ok=false;
                break;
            }
        }
        if(ok){
            mx=mid;
            R=mid-1;
        }
        else L=mid+1;
    }
    L=0,R=l;
    int mn=0;
    while(L<=R){
        int mid=(L+R)/2;
        bool ok=true;
        int maxi=-2e18;
        for(int k=1;k<=n;k++){
            maxi=max(maxi,A[k-1]-(k-1)*mid);
            if(B[k]-k*mid<maxi){
                ok=false;
                break;
            }
        }
        if(ok){
            mn=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }

    vector<int> lef(n+1),rig(n+1);
    for(int i=1;i<=n;i++){
        lef[i]=max(A[i],lef[i-1]+mn);
        rig[i]=min(B[i],rig[i-1]+mx);
    }
    lef[n]=max(lef[n],l);
    rig[n]=min(rig[n],l);

    for(int i=n-1;i>=1;i--){
        lef[i]=max(lef[i],lef[i+1]-mx);
        rig[i]=min(rig[i],rig[i+1]-mn);        
    }

    vector<int> res(n+1);
    for(int i=1;i<=n;i++){
        res[i]=max(lef[i],res[i-1]+mn);
        cout<<res[i-1]<<" "<<res[i]<<'\n';
    }



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