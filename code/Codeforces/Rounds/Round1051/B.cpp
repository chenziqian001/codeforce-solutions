#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    vector<long long> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    vector<int> b(k);
    for(int i=0;i<k;i++) cin>>b[i];
    
    sort(b.begin(),b.end());
    int posa=0;
    long long res=0;
    for(int i=0;i<k;i++){
        int len=b[i];
        if(posa+len>n){
            res+=pre[n]-pre[posa];
            posa=n;
            break;
        }
        else{
            res+=pre[posa+len-1]-pre[posa];
            posa=posa+len;
        }
    }
    if(posa<n){
        res+=pre[n]-pre[posa];
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