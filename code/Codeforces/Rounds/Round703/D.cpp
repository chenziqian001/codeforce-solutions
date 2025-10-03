#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n;
    int res;
    while(l<=r){
        int mid=(l+r)/2;
        vector<int> b(n+1);
        vector<int> pre(n+1);
        for(int i=1;i<=n;i++){
            if(a[i]>=mid) b[i]=1;
            else b[i]=-1;
            pre[i]=pre[i-1]+b[i];
        }
        int mn=inf,flag=0;
        for(int i=k;i<=n;i++){
            mn=min(mn,pre[i-k]);
            if(pre[i]-mn>0){
                flag=1;
                break;
            }
        }
        if(flag){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res<<'\n';
    system("pause");

}