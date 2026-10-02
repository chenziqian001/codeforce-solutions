#include<bits/stdc++.h>
using namespace std;
#define int long long




void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(k+1),b(k+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=k) a[x]=1;
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(x<=k) b[x]=1;
    }


    int c1=0,c2=0;
    for(int i=1;i<=k;i++){
        if((!a[i]) && (!b[i])){
            cout<<"NO"<<'\n';
            return;
        }
        if((!a[i]) && b[i]) c1++;
        if((!b[i]) && a[i]) c2++;
    }
    if(c1<=k/2 && c2<=k/2){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';

    
  
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