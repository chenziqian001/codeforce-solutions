#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;


    int q=(n+k-1)/k;
    vector<int> a(n+1);
    vector<int> c(n+1);

    for(int b=1;b<=q;b++){
        int l=k*(b-1)+1,r=min(n,k*b);
        int s=r-l+1;
        int m=s/2;
        for(int i=l;i<=r;i++){
            c[i]=b;
            if(i<l+s-m){
                a[i]=i+m;
            }
            else{
                a[i]=i-(s-m);
            }
        }
    }


    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
    cout<<q<<'\n';
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}