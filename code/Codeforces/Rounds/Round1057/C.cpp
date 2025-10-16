#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    }
    int m=b.size();
    vector<int> cnt(m);
    for(int i=0;i<n;i++) cnt[a[i]]++;
    int res=0;
    int cur=0;
    int num=0;
    
    vector<int> remain;
    for(int i=0;i<m;i++){
        if(cnt[i]%2==1) remain.push_back(b[i]);
        cur+=2*b[i]*(cnt[i]/2);
        num+=cnt[i]/2;
    }
    res=max(res,cur);
    int ans=res;
    sort(remain.rbegin(),remain.rend());
    bool extra=false;
    for(int i=0;i<remain.size();i++){
        if(res>remain[i]){
            ans=max(ans,res+remain[i]);
            extra=true;
            break;
        }
    }
    for(int i=1;i<remain.size();i++){
        if(remain[i-1]-remain[i]<res){
            ans=max(ans,res+remain[i]+remain[i-1]);
            extra=true;
            break;
        }
    }
    if(num==0 || (num==1&&(!extra))) cout<<0<<'\n';
    else cout<<ans<<'\n';
}
 
 
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}