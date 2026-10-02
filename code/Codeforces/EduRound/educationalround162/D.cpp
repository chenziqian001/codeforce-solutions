#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int lg2[N];
void init(){
    lg2[1]=0;
    for(int i=2;i<N;i++){
        lg2[i]=lg2[i/2]+1;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int lg=lg2[n]+1;

    vector<vector<int>> st1(n+1,vector<int>(lg)),st2(n+1,vector<int>(lg));
    for(int i=1;i<=n;i++) st1[i][0]=a[i];
    for(int i=1;i<=n;i++) st2[i][0]=a[i];

    for(int j=1;j<lg;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
            st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
        }
    }
    auto get1=[&](int l,int r){
        int k=lg2[r-l+1];
        int val=max(st1[l][k],st1[r-(1<<k)+1][k]);
        return val;
    };
    auto get2=[&](int l,int r){
        int k=lg2[r-l+1];
        int val=min(st2[l][k],st2[r-(1<<k)+1][k]);
        return val;
    };

    vector<int> res(n+1,-1);
    for(int i=1;i<=n;i++){
        int l=1,r=n;
        int val=-1;
        while(l<=r){
            int mid=(l+r)/2;
            bool ok=false;
            int R=min(n,i+mid);
            if(R>i){
                if(a[i+1]>a[i]) ok=true;
                else if(s[R]-s[i]>a[i] && get1(i+1,R)!=get2(i+1,R)) ok=true;
            }
            int L=max(1LL,i-mid);
            if(!ok && L<i){
                if(a[i-1]>a[i]) ok=true;
                else if(s[i-1]-s[L-1]>a[i] && get1(L,i-1)!=get2(L,i-1)) ok=true;
            }
            
            if(ok){
                val=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        res[i]=val;
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}