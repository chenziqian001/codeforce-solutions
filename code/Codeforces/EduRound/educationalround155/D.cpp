#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for(int bit=0;bit<30;bit++){
        vector<int> b(n);
        for(int i=0;i<n;i++){
            b[i]=(a[i]>>bit)&1;
        }
        vector<int> cnt(2,0);
        vector<int> lensum(2,0);
        cnt[0]=1;
        int px=0;
        int bc=0;
        for(int i=0;i<n;i++){
            px^=b[i];
            int tg=px^1;
            bc=(bc+(cnt[tg]*(i+1)%mod-lensum[tg]+mod)%mod)%mod;
            cnt[px]=(cnt[px]+1)%mod;
            lensum[px]=(lensum[px]+i+1)%mod;
        }
        res=(res+bc*((1<<bit)%mod)%mod)%mod;

    }
    cout<<res<<'\n';
    system("pause");
    return 0;
}




