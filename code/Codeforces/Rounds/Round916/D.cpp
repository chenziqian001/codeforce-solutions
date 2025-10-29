#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    vector<int> aid(n);
    vector<int> bid(n);
    vector<int> cid(n);
    for(int i=0;i<n;i++) aid[i]=i;
    for(int i=0;i<n;i++) bid[i]=i;
    for(int i=0;i<n;i++) cid[i]=i;
    sort(aid.begin(),aid.end(),[&](int x,int y){
        return a[x]>a[y];
    });
    sort(bid.begin(),bid.end(),[&](int x,int y){
        return b[x]>b[y];
    });
    sort(cid.begin(),cid.end(),[&](int x,int y){
        return c[x]>c[y];
    });
    int res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(aid[i]==bid[j] || bid[j]==cid[k] || aid[i]==cid[k]) continue;
                res=max(res,a[aid[i]]+b[bid[j]]+c[cid[k]]);
            }
        }
    }
    cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  t;
    cin>>t;
    while(t--) solve();
    return 0;
}