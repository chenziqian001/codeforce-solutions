#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    if(a[0]==1 || (n==1 && a[0]==2)){
        cout<<0<<'\n';
        return;
    }
    int res=a[0];
    int re=a[0]/2;
    for(int i=1;i<n;i++){
        if(a[i]>=2){
            res+=a[i];
            if(i==1) re--;
            re+=((a[i]/2)-1);
        }
        else{
            if(re){
                re--;
                res++;
            }
            else break;
        }
    }
    cout<<res<<'\n'; 
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}
