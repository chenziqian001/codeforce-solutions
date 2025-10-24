#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,l,k;
    cin>>n>>k>>l;
    l*=2;k*=2;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]*=2;
    }
    int t=a[0],pos=k;
    for(int i=1;i<n;i++){
        if(a[i]-t<=pos){
            pos=min(pos,a[i]+t)+k;
        }
        else{
            int add=(a[i]-t-pos)/2;
            pos=(a[i]-t+pos)/2+k;
            t+=add;
        }
        if(pos>=l) break;
    }
    if(pos<l) t+=l-pos;
    cout<<t<<'\n';    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


