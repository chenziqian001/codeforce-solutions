#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    string s;
    cin>>s;
    int mx=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int l=0,r=mx;
    int res=mx;
    auto check=[&](int mid){
        int cnt=0;
        bool inbloc=false;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                if(s[i]=='R'){
                    inbloc=false;
                }
                else{
                    if(!inbloc){
                        cnt++;
                        inbloc=true;
                    }
                }
            }
        }
        return cnt<=k;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}