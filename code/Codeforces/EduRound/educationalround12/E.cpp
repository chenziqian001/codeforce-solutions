#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int son[N*30][2],sum[N*30],id=0;
const int h=30;
void add(int x){
    int p=0;
    for(int i=h;i>=0;i--){
        int bit=(x>>i)&1;
        if(!son[p][bit]) son[p][bit]=++id;
        p=son[p][bit];
        sum[p]++;
    }
}
int get(int x,int l){
    int p=0;
    int res=0;
    for(int i=h;i>=0;i--){
        int bx=(x>>i)&1;
        int bl=(l>>i)&1;
        if(bl==0){
            if(son[p][bx^1]) res+=sum[son[p][bx^1]];
            if(!son[p][bx]) return res;
            p=son[p][bx];
        }
        else{
            if(!son[p][bx^1]) return res;
            p=son[p][bx^1];
        }
    }
    res+=sum[p];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i-1];
    }
    long long res=0;
    for(int i=1;i<=n;i++){
        add(pre[i-1]);
        res+=get(pre[i],k);
    }
    cout<<res<<'\n';
    return 0;
}