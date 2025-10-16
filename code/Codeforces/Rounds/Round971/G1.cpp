#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
multiset<int> s;

void add(int x,int y,vector<int> &num){
    if(num[x]) s.erase(s.find(num[x]));
    num[x]+=y;
    if(num[x])s.insert(num[x]);
}
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    s.clear();
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x-i+n;
    }
    vector<int> num(n*8+10);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(i>=k) add(a[i-k],-1,num);
        add(a[i],1,num);
        if(i>=k-1)ans[i]=k-*s.rbegin();
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<ans[r]<<'\n';
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