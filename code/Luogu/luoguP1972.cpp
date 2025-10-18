#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],bit[N],last[N];
int ans[N];
int n;
struct node{
    int l,r,id;
    bool operator<(const node &other) const {
        return r<other.r;
    };
    
};
void add(int pos,int val){
    for(int i=pos;i<=n;i+=i&-i){
        bit[i]+=val;
    }
}
int sum(int i){
    int res=0;
    for(;i>=1;i-=i&-i) res+=bit[i];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int m;
    cin>>m;
    vector<node> q(m);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        q[i]={l,r,i};
    }
    sort(q.begin(),q.end());
    int cur=0;
    for(auto &x:q){
        while(cur<x.r){
            cur++;
            int val=a[cur];
            if(last[val]){
                add(last[val],-1);
            }
            add(cur,1);
            last[val]=cur;
        }
        ans[x.id]=sum(x.r)-sum(x.l-1);
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<'\n';
    }
}