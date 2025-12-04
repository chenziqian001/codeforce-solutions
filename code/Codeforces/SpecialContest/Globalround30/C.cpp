#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(m);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>c[i];
    
    multiset<int> s(a.begin(),a.end());
    vector<tuple<int,int,int>> all(m);
    for(int i=0;i<m;i++){
        all[i]={(int)c[i]==0,b[i],i};
    }

    sort(all.begin(),all.end());
    int res=0;


    for(auto &[j,k,i]:all){
        auto it=s.lower_bound(b[i]);
        if(it!=s.end()){
            res++;
            int val=*it;
            s.erase(it);
            if(c[i]){
                s.insert(max(val,c[i]));
            }
        }
    }
    cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}