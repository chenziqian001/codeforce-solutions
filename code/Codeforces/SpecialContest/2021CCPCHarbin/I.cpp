#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
#define int long long



void solve(){
    int n;
    cin>>n;


    vector<int> cnt(35);
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        for(int j=0;j<32;j++){
            if(x>>j&1) cnt[j]++;
        }
    }


    while(true){
        bool ok=false;
        for(int i=32;i>=1;i--){
            if(cnt[i]>cnt[i-1]){
                int d=cnt[i]-cnt[i-1];
                int s=(d+2)/3;
                cnt[i]-=s;
                cnt[i-1]+=s*2;
                ok=true;
            }
        }
        if(!ok) break;
    }
    cout<<cnt[0]<<'\n';



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



