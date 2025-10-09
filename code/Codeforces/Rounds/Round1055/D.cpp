#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> pre(n+1),hf(n+1);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+(__lg(a[i]));
        hf[i+1]=hf[i];
        if(a[i]&(a[i]-1)){
            if((a[i]-1)&(a[i]-2)){
                pre[i+1]++;
            }
            else hf[i+1]++;
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]+(hf[r]-hf[l-1])/2<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}

