#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        auto it =s.upper_bound(r);
        if(it!=s.end()) s.erase(it);
        s.insert(l);
        cout<<s.size()<<" ";
    }
    cout<<'\n';

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}