#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),c(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    if(c[a[n-1]]<k || c[a[0]]<k){
        cout<<"NO"<<'\n';
        return;
    }
    if(a[0]==a[n-1]){
        cout<<"YES"<<'\n';
        return;
    }
    else{
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[0] && c1<k) c1++;
            else if(c1==k && a[i]==a[n-1]) c2++;
        }
        if(c2>=k){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }



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

