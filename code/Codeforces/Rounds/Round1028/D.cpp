#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    
    string c;
    cin>>c;

    int res=0;
    for(int i=0;i<n;i++){
        res=res^b[i];
        b[i]^=a[i];
    }
    
    for(int j=59;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(b[i] && __lg(b[i])){
                if((c[i]-'0')!=((res>>j)&1)) res^=b[i];
                for(int k=0;k<i;k++){
                    if((b[k]>>j)&1) b[k]^=b[i];
                }
                break;
            }
        }
    }
    

    cout<<res<<'\n';
}



signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}