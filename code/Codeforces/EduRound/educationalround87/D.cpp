#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,q;
    cin>>n>>q;

    vector<int> fw(n+1);
    auto add=[&](int pos,int val){
        for(int i=pos;i<=n;i+=i&-i){
            fw[i]+=val;
        }
    };
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        add(x,1);
    }

    while(q--){
        int k;
        cin>>k;
        if(k>0){
            add(k,1);
        }
        else{
            k=-k;
            int pos=0;
            for(int i=20;i>=0;i--){
                if(pos+(1<<i)<=n && fw[pos+(1LL<<i)]<k){
                    pos+=(1LL<<i);
                    k-=fw[pos];
                }
            }
            add(pos+1,-1);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(fw[i]){
            res=i;
            break;
        }
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}