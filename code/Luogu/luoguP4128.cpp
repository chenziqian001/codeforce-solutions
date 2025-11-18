#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int inf=1e18;


/*
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(n+1,inf);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        int mx=0;
        for(int j=i;j>=1;j--){
            sum+=a[j];
            mx=max(mx,a[j]);
            if(sum<=m){
                dp[i]=min(dp[i],dp[j-1]+mx);
            }
            else break;
        }
    }

    cout<<dp[n]<<'\n';
    //system("pause");
}
*/
//很显然，以上做法的复杂度是O(n^2)的


int h[N];
int w[N];
int f[N];
int n,m;

struct node{
    int l,r;
    int f,ans;
    int laze;
};


struct segt{
    node t[N*4];
    void push_up(int i){
        t[i].f=min(t[i<<1].f,t[i<<1|1].f);
        t[i].ans=min(t[i<<1].ans,t[i<<1|1].ans);
    }

    void ap(int i,int val){
        t[i].ans=t[i].f+val;
        t[i].laze=val;
    }
    void push_down(int i){
        if(t[i].laze!=inf){
            ap(i*2,t[i].laze);
            ap(i*2+1,t[i].laze);
            t[i].laze=inf;
        }
    }

    void build(int i,int l,int r){
        t[i].f=inf;
        t[i].ans=inf;
        t[i].laze=inf;
        t[i].l=l,t[i].r=r;
        int mid=(l+r)/2;
        if(l==r) return;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
    }

    void upd(int i,int l,int r,int val){
        if(l<=t[i].l && t[i].r<=r){
            ap(i,val);
            return;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)>>1;
        if(l<=mid){
            upd(i*2,l,r,val);
        }
        if(r>mid){
            upd(i*2+1,l,r,val);
        }
        push_up(i);
    }

    void change(int i,int pos){
        if(t[i].l==t[i].r){
            t[i].ans=inf;
            t[i].f=f[pos-1];
            return;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(pos<=mid) change(i*2,pos);
        else change(i*2+1,pos);
        push_up(i);
    }

    int query(int i,int l,int r){
        if(l<=t[i].l && t[i].r<=r){
            return t[i].ans;
        }
        push_down(i);
        int res=inf;
        int mid=(t[i].l+t[i].r)/2;
        if(l<=mid){
            res=min(res,query(i*2,l,r));
        }
        if(r>mid){
            res=min(res,query(i*2+1,l,r));
        }
        return res;
    }
} t;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i]>>w[i];
        pre[i]=pre[i-1]+w[i];
        if(w[i]>m){
            cout<<-1<<'\n';
            return 0;
        }
    }
    
    stack<int> st;
    vector<int> next(n+1);
    
    st.push(1);
    for(int i=2;i<=n;i++){
        while(!st.empty() && h[i]>=h[st.top()]) st.pop();
        if(!st.empty()) next[i]=st.top();
        st.push(i);
    }
    
    t.build(1,1,n);

    for(int i=1;i<=n;i++){
        t.change(1,i);
        
        if(next[i]<i) t.upd(1,next[i]+1,i,h[i]);
        int l=1,r=n;
        int res=l;
        while(l<=r){
            int mid=(l+r)/2;
            if(pre[i]-pre[mid-1]>m){
                l=mid+1;
            }
            else{
                res=mid;
                r=mid-1;
            }
        }


        if(res<=i) f[i]=t.query(1,res,i);
    }

    cout<<f[n]<<'\n';
    //system("pause");
}// 和p1295几乎完全一致