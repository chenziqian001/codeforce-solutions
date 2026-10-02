#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int S=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        S+=a[i];
    }
   
    S/=2; 
    
    int ans=0;
    if(n%2!=0) {
        int x0=0;
        int sign=1;
        for(int i=0;i<n;i++) {
            x0+=sign*a[i];
            sign=-sign;
        }
        x0/=2; 
        int mx=x0;
        int cur=x0;
        for(int i=0;i<n-1;i++) {
            cur=a[i]-cur;
            mx=max(mx,cur);
        }
        ans=max(mx,(S+n-2)/(n-1));
    } else {
        int P=0, L=0, R=4e18, m0=0, m1=-4e18;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                L=max(L,-P);
                m0=max(m0,P);
            } else {
                R=min(R,P);
                m1=max(m1,P);
            }
            P=a[i]-P;
        }
        int k_opt=(m1-m0)/2;
        int k1=max(L,min(R,k_opt));
        int k2=max(L,min(R,k_opt+1));
        int mx1=max(m0+k1,m1-k1);
        int mx2=max(m0+k2,m1-k2);
        int mx=min(mx1,mx2);
        
        ans=max(mx,(S+n-2)/(n-1));
    }
    cout<<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}