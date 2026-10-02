#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int p[7]={1,10,100,1000,10000,100000,1000000};
    for(int x=p[a-1];x<p[a];x++){
        int l=max(p[b-1],p[c-1]-x);
        int r=min(p[b]-1,p[c]-1-x);
        int len=max(0LL,r-l+1);
        if(k<=len){
            cout<<x<<" + "<<l+k-1<<" = "<<x+l+k-1<<'\n';
            return;
        }
        k-=len;
    }
    cout<<-1<<'\n';
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
