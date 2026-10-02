#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    vector<int> p(n+1),q(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        p[b[i]]=i;
    } 
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q[x]=i;
    }



    int res=1;


    int x=0,y=0,z=0;
    for(int i=1;i<n;i++){
        x=max(x,p[a[i]]);
        y=max(y,q[a[i]]);
        z=max(z,q[b[i]]);

        if(x==i || y==i || z==i){
            res++;
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
}