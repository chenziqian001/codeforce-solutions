#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=10000000LL;



void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    int tt=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]*=inf;
        tt+=a[i];
    }


    int need;


    if(tt==(100LL*inf)){
        need=0LL;
    }
    else if(tt>(100LL*inf)){
        need=tt-100LL*inf;
        for(int i=0;i<n;i++){
            if(a[i]){
                a[i]-=min(inf/2LL,need);
                need-=min(inf/2LL,need);
            }
        }
    }
    else{
        need=100LL*inf-tt;
        for(int i=0;i<n;i++){
            if(a[i]<(100LL*inf)){
                a[i]+=min(need,inf/2-1LL);
                need-=min(need,inf/2-1LL);
            }

        }
    }


    if(need){
        cout<<"NO"<<'\n';
    }
    else{
        cout<<"YES"<<'\n';
        for(int x:a){
            cout<<x<<" ";
        }
        cout<<'\n';
    }   
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}




