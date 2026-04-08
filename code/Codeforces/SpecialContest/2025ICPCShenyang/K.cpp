#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,s;
    cin>>n>>s;
    s--;


    vector<int> sx(n);
    vector<int> tx(n);
    vector<int> sy(n);
    vector<int> ty(n);


    for(int i=0;i<n;i++){
        cin>>sx[i]>>sy[i]>>tx[i]>>ty[i];
    }

    int sum_sx=accumulate(sx.begin(),sx.end(),0LL);
    int sum_sy=accumulate(sy.begin(),sy.end(),0LL);
    int sum_tx=accumulate(tx.begin(),tx.end(),0LL);
    int sum_ty=accumulate(ty.begin(),ty.end(),0LL);


    int resx=(sum_tx-sum_sx)/2+sx[s];
    int resy=(sum_ty-sum_sy)/2+sy[s];

    for(int i=0;i<n;i++){
        if(tx[i]==resx && ty[i]==resy){
            cout<<i+1<<'\n';
            return;
        }
    }






}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}