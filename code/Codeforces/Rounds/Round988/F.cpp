#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int h[N];
int pos[N];
int n,m,k;
bool check(int val){
    map<int,int> diff;

    for(int i=0;i<n;i++){
        int ma=(h[i]+val-1)/val;
        if(ma>m) continue;

        int dis=m-ma;

        int st=pos[i]-dis;
        int ed=pos[i]+dis;

        diff[st]+=1;
        diff[ed+1]-=1;
    }

    int cur=0;

    for(auto [_,v]:diff){
        cur+=v;
        if(cur>=k){
            return true;
        }
    }
    return false;
}


void solve(){
    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>pos[i];

    int lo=1;
    int hi=2e9+10;

    int res=hi;
    while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(check(mid)){
            res=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }

    if(res>=2e9+10){
        cout<<-1<<'\n';
    }
    else cout<<res<<'\n';


}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
}