#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    vector<int> d(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>d[i];
    int q;
    cin>>q;
    map<int,vector<int>> mpl,mpr;
    map<int,int> pos2d;
    for(int i=0;i<n;i++){
        pos2d[p[i]]=d[i];
        mpl[(d[i]+p[i])%k].emplace_back(p[i]);
        mpr[((d[i]-p[i])%k+k)%k].emplace_back(p[i]);
    }

    auto get_left=[&](int pos,int t){
        int val=(t+pos)%k;
        auto &vec=mpl[val];
        auto it=lower_bound(vec.begin(),vec.end(),pos);
        if(it==vec.begin()) return -1LL;
        it--;
        return *it;
    };

    auto get_right=[&](int pos,int t){
        int val=((t-pos)%k+k)%k;
        auto &vec=mpr[val];
        auto it=lower_bound(vec.begin(),vec.end(),pos+1);
        if(it==vec.end()) return -1LL;
        return *it;
    };

    map<pair<int,int>,int> memo;


    while(q--){
        int x;
        cin>>x;
        int dir=1,t=0;
        set<pair<int,int>> st;
        bool ok=false;
        if(pos2d.count(x) && pos2d[x]==0) dir^=1;
        for(int i=0;i<2*n;i++){
            int y=dir?get_right(x,t):get_left(x,t);
            if(y==-1){
                ok=true;
                break;
            }
            else{
                t+=abs(y-x);
                x=y;
                dir^=1;
            }
            if(st.count({x,dir})) break;
            st.insert({x,dir});
            if(memo.count({x,dir})){
                ok=memo[{x,dir}];
                break;
            }
        }
        for(auto [a,b]:st){
            memo[{a,b}]=ok;
        }

        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }



}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}