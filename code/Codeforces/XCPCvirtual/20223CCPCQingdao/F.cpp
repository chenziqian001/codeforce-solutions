#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<bool> p(200005,1);
    p[0]=p[1]=0;

    for(int i=2;i*i<=200000;i++){
        if(p[i]){
            for(int j=i*i;j<=200000;j+=i) p[j]=0;
        }
    }

    int k=0,e=1,o=1,c=1,INF=1e9;
    for(int i=2;i<=n;i++){
        int nk=INF,ne=INF,no=INF,nc=INF;
        
        if(p[a[i-1]+a[i]])nk=min(nk,k);
        if(a[i]%2!=0) nk=min(nk,e);
        if(a[i]%2==0) nk=min(nk,o);
        if(p[a[i]+1]) nk=min(nk,c);

        if(a[i-1]%2!=0) ne=min(ne,k+1);
        ne=min({ne,o+1,c+1});

        if(a[i-1]%2==0) no=min(no,k+1);
        no=min(no,e+1);

        if(p[a[i-1]+1]) nc=min(nc,k+1);
        nc=min({nc,e+1,c+1});

        k=nk;e=ne;o=no;c=nc;
    }
    cout<<min({k,e,o,c})<<"\n";

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