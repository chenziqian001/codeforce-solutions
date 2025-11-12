#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
const int inf=-1e18;
int q[N];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,L,R;
    cin>>n>>L>>R;
    vector<int> a(n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
    vector<int> f(n+1,inf);
    f[0]=0;
    int l=1,r=0;
    for(int i=0;i<=n;i++){
        if(i-L>=0){
            while(l<=r && f[i-L]>=f[q[r]]) r--;
            q[++r]=i-L;
        }
        while(l<=r && q[l]<i-R) l++;

        if(l<=r) f[i]=max(f[i],f[q[l]]+a[i]);
    }
    int res=inf;
    for(int i=n;i>=max(1LL,n-R+1);i--){
        if(f[i]!=inf){
            res=max(res,f[i]);
        }
    }

    cout<<res<<'\n';
    //system("pause");
    

}