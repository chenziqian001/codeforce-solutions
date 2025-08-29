#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int x=0,y=0;
    int inc=0,dec=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]) x+=a[i];
        else if(a[i]<b[i]) y+=b[i];
        else{
            inc+=(a[i]>0);
            dec+=(a[i]<0);
        }
    }

    int res=-1e9;
    for(int i=-dec;i<=inc;i++){
        int cur=min(x+i,y+inc-dec-i);
        res=max(res,cur);
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