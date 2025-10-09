#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<vector<int>> divi(N); 

void init(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divi[j].push_back(i);
        }
    }
}


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    auto get_ans=[&](int l,int r,int k){
        vector<pair<int,int>> b={{r+1,-1}};
        for(int i:divi[k]){
            auto it=lower_bound(mp[i].begin(),mp[i].end(),l);
            if(it==mp[i].end() || *it>r) continue;
            b.emplace_back(*it,i);
        }
        sort(b.begin(),b.end());
        int res=0;
        for(auto [x,y]:b){
            res+=(x-l)*k;
            if(x>r) break;
            while(k%y==0) k/=y;
            l=x;
        }

        return res;
    };
    while(q--){
        int k,l,r;
        cin>>k>>l>>r;
        l--,r--;
        int ans=get_ans(l,r,k);
        cout<<ans<<'\n';
    }
}





signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}