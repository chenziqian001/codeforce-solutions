#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    int m=(1<<n);
    vector<int> res(m);
    vector<pair<int,int>> a(m),t(m); 
    for(int i=0;i<(1<<n);i++){
        int x;
        cin>>x;
        a[i]={x,i};
    }
    for(int R=1;R<=n;R++){
        int L=1<<R,H=L>>1;
        for(int i=0;i<m;i+=L){
            int p1=i,p2=i+H,p=i;
            
            while(p1<i+H&&p2<i+L)t[p++]=a[p1].first<a[p2].first?a[p1++]:a[p2++];
            while(p1<i+H)t[p++]=a[p1++];
            while(p2<i+L)t[p++]=a[p2++];
            
            for(int j=0;j<L;j++){
                a[i+j]=t[i+j];
                if(a[i+j].first>=L&&j+1>=L-k) res[a[i+j].second]=R;
            }
        }
    }
    for(int i=0;i<m;i++) cout<<res[i]<<" ";
    cout<<'\n';
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}
