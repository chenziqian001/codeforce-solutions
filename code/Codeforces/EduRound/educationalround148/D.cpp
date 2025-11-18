#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a.begin(),a.end());
    


    vector<int> f(n+1,inf);
    for(int i=0;i<n;i++){
        f[i+1]=min(f[i]+1LL,a[i]+1LL);
    }

    while(q--){
        int k;
        cin>>k;
        int s=sum;
        if(k<n){
            cout<<min(f[k],a[k])<<" ";
        }
        else{
            int res;
            if((k-n)%2==0){
                res=f[n]+k-n;
                s+=n*(k+k-n+1)/2-(k-n)/2;
            }
            else{
                res=min(a[n-1],f[n-1]+k-n+1);
                s+=(n-1)*(k+k-n+2)/2-(k-n+1)/2;
            }
            int ans = std::min(1LL * res, s >= 0 ? s / n : (s - n + 1) / n);
            std::cout << ans << " ";
        }
    }
    //system("pause");



}

