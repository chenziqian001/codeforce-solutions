#include<bits/stdc++.h>
using namespace std;
#define int long long


bool check(int mid,vector<int> &a,vector<int> &b){
    int n=a.size();
    int maxi=*max_element(a.begin(),a.end());
    int mini=*min_element(a.begin(),a.end());
    
    int lb=maxi-mid;
    int rb=mini+mid;

    for(int i=0;i<n;i++){
        if(a[i]>lb && a[i]<rb){
            if(a[i]!=b[i]){
                return false;
            }
        }
    }

    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());


    if(a==b){
        cout<<-1<<'\n';
        return;
    }

    int l=0,r=1e9+7;
    int res=r;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,a,b)){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<res<<'\n';

    
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

