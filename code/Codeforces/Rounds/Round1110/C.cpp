#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        if(k==1){
            cout<<"YES"<<'\n';
            cout<<0<<'\n';
            
        }else{
            cout<<"NO"<<'\n';
        }
        return;
    }
    k^=n;
    int bk=k==0?0:32-__builtin_clz(k);
    int bn=32-__builtin_clz(n-1);
    
    if(bk>bn){
        cout<<"NO"<<'\n';
        return;
    }
    vector<int> s;
    
    if(k>0&&k<=n-1){
        s.push_back(k);
    }else if(k>0){
        s.push_back(n-1);
        s.push_back((n-1)^k);
    }
    s.push_back(0);
    vector<int> a=s;
    vector<bool> vis(n,false);
    for(int x:s) vis[x]=true;
    for(int i=0;i<n;i++){
        if(!vis[i]) a.push_back(i);
    }
    cout<<"YES"<<'\n';
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<(i==0?"":" ");
    }
    cout<<'\n';
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