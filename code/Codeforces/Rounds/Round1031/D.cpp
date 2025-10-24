#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> fstm(n);
    vector<int> secm(n);
    int m1=INT_MAX,m2=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]<m1){
            m2=m1;
            m1=a[i];
        }    
        else if(a[i]<m2){
            m2=a[i];
        }
        fstm[i]=m1;
        secm[i]=m2;
    }
    
    vector<int> pbm(n); 
    pbm[0]=b[0];
    for(int i=1;i<n;i++) pbm[i]=min(pbm[i-1],b[i]);
    
    vector<int> sam(n+1);
    sam[n]=0;
    for(int i=n-1;i>=0;i--) sam[i]=max(sam[i+1],a[i]);

    int l=1,r=n;
    int res=0;
    auto check=[&](int x){
        if(fstm[x-1]>pbm[n-x]) return true;
        int e = sam[x];
        if(min(max(e,fstm[x-1]),secm[x-1])>pbm[n-x]) return true;
        return false;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}