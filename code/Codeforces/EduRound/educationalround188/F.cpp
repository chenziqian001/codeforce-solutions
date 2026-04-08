#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂
int inv(int x) {return qp(x,mod-2);}//逆元

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n+1);
    vector<int> k(m);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>k[i];

    vector<int> L(n+1,0),R(n+1,n+1);

    stack<int> st;
    for(int i=1;i<=n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()) L[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();


    for(int i=n;i>=1;i--){
        while(!st.empty() && a[st.top()] > a[i]){
            st.pop();
        }
        if(!st.empty()) R[i]=st.top();
        st.push(i);
    }


    int sum=0;
    vector<pair<int,int>> p(n);
    for(int i=1;i<=n;i++){
        int cnt=(i-L[i])*(R[i]-i)%mod;
        p[i-1]={a[i],cnt};


        int tt=i*(n-i+1)%mod;
        sum=(sum+tt*inv(a[i])%mod)%mod;
    }
    sort(p.begin(),p.end());


    int s1=0,s2=0,s3=0;
    for(int i=0;i<n;i++) s1=(s1+p[i].second*inv(p[i].first)%mod)%mod;

    int idx=0;
    for(int i=0;i<m;i++){
        int q=k[i];
        while(idx<n&&p[idx].first<=q+1){
            int v=p[idx].first,c=p[idx].second;
            int iv=inv(v);

            s1=(s1-c*iv%mod+mod)%mod;
            s2=(s2+c)%mod;
            
            int t3=(2-v%mod+mod)%mod; 
            t3=(t3-iv+mod)%mod;       
            s3=(s3+c*t3)%mod;
            
            idx++;
        }
        int res=sum;
        res=(res+q%mod*s1)%mod;
        res=(res+q%mod*s2)%mod;
        res=(res+s3)%mod;

        cout<<res<<'\n';
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}