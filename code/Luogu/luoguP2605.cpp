#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+10;
const int inf=1e18;


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
        t[i].val=min(t[i<<1].val,t[i<<1|1].val);
    }

    void apply(int i,int v){
        t[i].val+=v;
        t[i].tag+=v;
    }

    void build(vector<int> &a,int i,int l,int r){
        t[i].l=l,t[i].r=r;
        t[i].tag=0;
        if(l==r){
            t[i].val=a[l];
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
        return min(query(i*2+1,l,r),query(i*2,l,r));
    }
};


int d[N];
int c[N];
int w[N];
int s[N];
int l[N],r[N];
pair<int,int> a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=2;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        l[i] = lower_bound(d+1, d+1+n, d[i]-s[i]) - d;
        r[i] = upper_bound(d+1, d+1+n, d[i] + s[i]) - d - 1;
        a[i]={r[i],i};
    }

    sort(a+1,a+1+n);
    int res=0;
    for(int i=1;i<=n;i++){
        res+=w[i];
    }

    vector<int> cost(n+2);
    for(int i=n;i>=1;i--){
        cost[l[i]-1]+=w[i];
    }

    for(int i=n;i>=1;i--) cost[i]+=cost[i+1];

    int cur=0;
    vector<int> f(n+1);
    for(int i=1;i<=n;i++){
        f[i]=cur+c[i];
        int loc=lower_bound(a+1,a+1+n,make_pair(i,0))-a;
        while(loc <= n && a[loc].first==i){
            cur+=w[a[loc].second];
            loc++;
        }
        res=min(res,f[i]+cost[i]);
    }

    segt st(n+1);

    for(int j=2;j<=k;j++){
        st.build(f,1,1,n);
        for(int i=j;i<=n;i++){
            f[i]=st.query(1,j-1,i-1)+c[i];
            res=min(res,f[i]+cost[i]);
            int loc=lower_bound(a+1,a+1+n,make_pair(i,0))-a;
            while(loc <= n && a[loc].first==i){
                int L = l[a[loc].second]-1;
                if(L >= 1) st.upd(1,1,L,w[a[loc].second]); // 仅在 L>=1 时更新区间 [1,L]
                loc++;
            }
        }
    }

    cout<<res<<'\n';
    
    //system("pause");
}


/*
int d[N];
int c[N];
int w[N];
int s[N];
int l[N],r[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=2;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        l[i]=lower_bound(d+1,d+1+n,d[i]-s[i])-d;
        r[i]=lower_bound(d+1,d+1+n,s[i]+d[i])-d;
        r[i]-=(s[i]+d[i]<d[r[i]]);
    }

    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));

    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+w[i];
    }

    int res=dp[n][0];

    for(int i=1;i<=n;i++){
        vector<int> cost(n+1);
        for(int j=i-1;j>=1;j--){
            if(r[j]<i){
                cost[l[j]-1]+=w[j];
            }
        }
        for(int j=i-1;j>=0;j--){
            cost[j]+=cost[j+1];
        }
        for(int j=1;j<=k && j<=i;j++){
            if(j==1){
                dp[i][j]=cost[0]+c[i];
            }
            else{
                for(int p=i-1;p>=j-1;p--){
                    dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p]+c[i]);
                }
            }
            int sum=0;
            for(int p=i+1;p<=n;p++){
                if(l[p]>i) sum+=w[p];
            }
            res=min(res,dp[i][j]+sum);
        }
    }

    cout<<res<<'\n';
    //system("pause");
    return 0;
}
*/