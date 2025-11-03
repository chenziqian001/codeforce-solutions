#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,q;
    cin>>n>>q;
    int ors=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        ors|=a[i];
    }
    int base=__builtin_popcountll(ors);
    vector<int> cost{0};
    int x=ors;

    for(int i=0;i<=30;i++){
        if(x>>i &1) continue;
        int c=cost.back();

        for(int j=i;j>=0;j--){
            int mask=(1<<j)-1;
            int pos=-1;
            bool ok=false;

            for(int k=0;k<n;k++){
                if(a[k]&(1<<j)){
                    ok=true;
                    break;
                }
                if(pos==-1 || ((a[k]&mask)>(a[pos]&mask))){
                    pos=k;
                }
            }
            if(ok) continue;
            c+=(1<<j)-(a[pos]&mask);
            a[pos]&=~mask;
            a[pos]|=(1<<j);
        }
        cost.push_back(c);
    }
    while(q--){
        int op;
        cin>>op;
        int count=upper_bound(cost.begin(),cost.end(),op)-cost.begin()-1;
        cout<<count+base<<'\n';

    }
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}




