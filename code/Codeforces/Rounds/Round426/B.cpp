#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<vector<int>> dp(n+1,vector<int>(k+1));
    int res=0;

    for(int i=1;i<=n;i++){
        vector<int> cnt(n+1);
        int tt=0;
        for(int j=i;j>=0;j--){
            if(j>0 && cnt[a[j]]==0){
                cnt[a[j]]++;
                tt++;
            }
            for(int c=1;c<=k;c++){
                if(j) dp[i][c]=max(dp[i][c],dp[j-1][c-1]+tt);
                res=max(res,dp[i][c]);
            }
        }
    }





    cout<<res<<'\n';
    system("pause");
}
*/
//显然，最朴素的dp做法，虽然简单，但是它揭示的转移方程是我们需要明确的

struct node{
    int l,r;
    int val,tag;
};

struct segt{
    vector<node> t;
    segt(int n){
        t.resize(n*4);
    }

    void push_up(int i){
        t[i].val=max(t[i<<1].val,t[i<<1|1].val);
    }

    void apply(int i,int v){
        t[i].val+=v;
        t[i].tag+=v;
    }

    void build(vector<int> &a,int i,int l,int r){
        t[i].l=l,t[i].r=r;
        t[i].tag=0;
        if(l==r){
            t[i].val=a[l-1];
            return;
        }
        int mid=(l+r)/2;
        build(a,i*2,l,mid);
        build(a,i*2+1,mid+1,r);
        push_up(i);
    }

    void push_down(int i){
        if(t[i].tag){
            apply(i*2,t[i].tag);
            apply(i*2+1,t[i].tag);
            t[i].tag=0;
        }
    }

    void upd(int i,int l,int r,int v){
        if(l<=t[i].l && t[i].r<=r){
            apply(i,v);
            return;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(l<=mid) upd(i*2,l,r,v);
        if(r>mid) upd(i*2+1,l,r,v);
        push_up(i);
    }


    int query(int i,int l,int r){
        if(l<=t[i].l && t[i].r<=r){
            return t[i].val;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(r<=mid) return query(i<<1,l,r);
        if(l>mid) return query(i<<1|1,l,r);
        return max(query(i*2+1,l,r),query(i*2,l,r));
    }
};

signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> last(n+1);
    vector<int> pre(n+1);

    for(int i=1;i<=n;i++){
        pre[i]=last[a[i]];
        last[a[i]]=i;
    }


    vector<int> f(n+1);

    segt st(n);

    for(int x=0;x<k;x++){
        st.build(f,1,1,n);
        for(int i=1;i<=n;i++){
            st.upd(1, pre[i]+1, i, 1);
            f[i] = st.query(1,1,i);
            cout << f[i] << " ";
        }
        cout << "\n";
    }


    cout<<f[n]<<'\n';
   
    system("pause");
}