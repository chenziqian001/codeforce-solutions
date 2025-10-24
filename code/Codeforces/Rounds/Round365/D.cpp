#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int bit[N];
int n;
void add(int i,int val){
    for(;i<=n;i+=i&-i){
        bit[i]^=val;
    }
}
int prexor(int i){
    int res=0;
    for(;i>=1;i-=i&-i){
        res=res^bit[i];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int> last;
    int m;
    cin>>m;
    
    vector<vector<pair<int,int>>> q(n+1);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        q[r].push_back({l,i});
    }

    vector<int> ans(m);
    vector<int> pre(n+1);


    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i];
        if(last.find(a[i])!=last.end()) add(last[a[i]],a[i]);
        add(i,a[i]);
        last[a[i]]=i;
        for(auto [l,id]:q[i]){
            int tot=prexor(i)^prexor(l-1);
            int val=tot^(pre[i]^pre[l-1]);
            ans[id]=val;
        }
    }
    for(int x:ans) cout<<x<<'\n';
}