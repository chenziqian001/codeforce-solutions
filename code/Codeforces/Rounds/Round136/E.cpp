#include<bits/stdc++.h>
using namespace std;
#define int long long
struct fenwick{
    int n;
    vector<int> fw;
    fenwick(int x){
        n=x;
        fw.resize(n);
    }


    void add(int pos,int val){
        for(int i=pos;i<n;i+=i&-i){
            fw[i]+=val;
        }
    }

    int query(int pos){
        int res=0;
        for(int i=pos;i>0;i-=i&-i){
            res+=fw[i];
        }
        return res;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    }

    fenwick suf(n+5);

    
    for(int i=n-1;i>=0;i--){
        int val=a[i];
        suf.add(val,1);
        k-=suf.query(val-1);
    }


    fenwick pre(n+5);
    int res=0;

    int l=0;
    for(int r=1;r<n;r++){
        suf.add(a[r-1],-1);
        k+=(l-pre.query(a[r-1]))+suf.query(a[r-1]-1);
        while(l<r){
            int inv=l-pre.query(a[l])+suf.query(a[l]-1);
            if(inv>k) break;
            k-=inv;
            pre.add(a[l],1);
            l++;
        }
        res+=l;
    }
    cout<<res<<'\n';
    //system("pause");
}