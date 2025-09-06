#include<bits/stdc++.h>
#define int long long

using namespace std;
int n,k;
void solve(){
    cin>>n>>k;
    
    vector<int> a(n);
    int res=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        res+=x/k;
    }
    int m;
    cin>>m;
    sort(a.begin(),a.end(),[&](int a,int b){
        return a%k > b%k;
    });
    for(int i=0;i<n;i++){
        int x=a[i];
        int remain=x%k;
        if(m>=(k-remain)){
            res++;
            m-=(k-remain);
        }
    }
    if(m>0){
        res+=m/k;
    }
    cout<<res<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}