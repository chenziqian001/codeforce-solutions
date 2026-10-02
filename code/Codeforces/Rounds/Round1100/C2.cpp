#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> suf(n+2);
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }   
    int pos=-1;
    int res=suf[1];
    int cur=0;
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            int val=cur-a[i]+suf[i+1];
            if(val>res){
                res=val;
                pos=i;
            }
        } 
        cur+=abs(a[i]);
    }
    vector<int> ans;
    int mul=1;
    for(int i=pos-1;i>=1;i--){
        if(a[i]*mul>=0){
            mul*=-1;
            ans.push_back(i);
        }
    }
    if(pos!=-1) ans.push_back(pos);
    cout<<ans.size()<<'\n';
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<'\n';
   
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

