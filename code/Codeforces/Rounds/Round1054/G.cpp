#include<bits/stdc++.h>
using namespace std;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int l,int r){
    uniform_int_distribution<int> dis(l,r);
    return dis(rng);
}



void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    }
    for(int i=0;i<n;i++){
        pos[a[i]].push_back(i); 
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int k=(r-l+1)/3;
        set<int> st;
        for(int i=0;i<50;i++){
            int id=l+rng()%(r-l+1);
            int x=a[id];
            int oc=upper_bound(pos[x].begin(),pos[x].end(),r)-lower_bound(pos[x].begin(),pos[x].end(),l);
            if(oc>k) st.insert(x);
        }
        if(st.size()==0) cout<<-1<<'\n';
        else{
            for(int x:st){
                cout<<b[x]<<" ";
            }
            cout<<'\n';
        }
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