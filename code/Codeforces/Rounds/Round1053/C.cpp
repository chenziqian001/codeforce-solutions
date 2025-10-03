/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = LLONG_MIN / 4;

int main() {
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> v(n+1);
        for (int i = 1; i <= n; ++i) cin >> v[i];

        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        // posInBob[item] = position of that item in Bob's order (1..n)
        vector<int> posInBob(n+1);
        for (int i = 1; i <= n; ++i) posInBob[b[i]] = i;

        // Build arrays according to Alice's order:
        // p[i] = position in Bob of the i-th item in Alice's order
        // val[i] = value of the i-th item in Alice's order
        vector<int> p(n+1);
        vector<ll> val(n+1);
        for (int i = 1; i <= n; ++i) {
            int item = a[i];
            p[i] = posInBob[item];
            val[i] = v[item];
        }

        // dp[i][j]: after processing first i items (Alice order),
        // Bob's maximum taken position = j, maximum Alice value
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, NEG));
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            int pi = p[i+1];
            ll vi = val[i+1];
            for (int j = 0; j <= n; ++j) {
                if (dp[i][j] == NEG) continue;
                ll cur = dp[i][j];

                // CASE 1: Bob takes item i+1 (always allowed)
                int newj = max(j, pi);
                dp[i+1][newj] = max(dp[i+1][newj], cur);

                // CASE 2: Alice takes item i+1 (only if j < pi)
                if (j < pi) {
                    dp[i+1][j] = max(dp[i+1][j], cur + vi);
                }
            }
        }

        ll ans = NEG;
        for (int j = 0; j <= n; ++j) ans = max(ans, dp[n][j]);
        cout << ans << '\n';
    }
    system("pause");
    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int inf = LLONG_MIN / 4;

int st[N<<2],laze[N<<2];
int n;

void push_up(int p,int l,int r){
    int mid=(l+r)/2;
    st[p]=max(st[p*2],st[p*2+1]);
}

void apply(int p,int val){
    st[p]+=val;
    laze[p]+=val;
}

void push_down(int p,int l,int r){
    if(laze[p]!=0){
        int mid=(l+r)/2;
        apply(p*2,laze[p]);
        apply(p*2+1,laze[p]);
        laze[p]=0;
    }
}

void build(int p=1,int l=1,int r=-1){
    if(r==-1) r=n+1;
    st[p]=inf;
    laze[p]=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    push_up(p,l,r);
}

void assign(int pos,int x,int p=1,int l=1,int r=-1){
    if(r==-1) r=n+1;
    if(l==r){
        st[p]=x;
        return;
    }
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(pos<=mid) assign(pos,x,p*2,l,mid);
    else assign(pos,x,p*2+1,mid+1,r);
    push_up(p,l,r);
}

void update(int k,int x,int p=1,int l=1,int r=-1){
    if(r==-1) r=n+1;
    if(r<=k){
        apply(p,x);
        return;
    }
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(k<=mid) update(k,x,p*2,l,mid);
    else {
        apply(p*2,x);
        update(k,x,p*2+1,mid+1,r);
    }
    push_up(p,l,r);
}

int query(int k,int p=1,int l=1,int r=-1){
    if(r==-1) r=n+1;
    if(r<=k) return st[p];
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(k<=mid) return query(k,p*2,l,mid);
    else{
        return max(st[p*2],query(k,p*2+1,mid+1,r));
    }

}

signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> _p(n+1),p(n+1);
        vector<int> v(n+1),_v(n+1);
        for(int i=1;i<=n;i++) cin>>_v[i];
        for(int i=1,a;i<=n;i++) cin>>a,_p[a]=i,v[i]=_v[a];
        for(int i=1,b;i<=n;i++) cin>>b,p[_p[b]]=i;
        build();
        assign(1,0);
        for(int i=1;i<=n;i++){
            
            assign(p[i]+1,query(p[i]));
            update(p[i],v[i]);
        }
        cout<<st[1]<<'\n';
    }
    system("pause");

}

