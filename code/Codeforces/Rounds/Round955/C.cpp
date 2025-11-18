#include<bits/stdc++.h>
using namespace std;
#define int long long



void  solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int s=0;
    
    int res=0;
    int lef=0;

    for(int i=0;i<n;i++){
        s+=a[i];
        while(s>r && lef<=i){
            s-=a[lef++];
        }
        if(s>=l){
            s=0;
            res++;
            lef=i+1;
        }
    }


    cout<<res<<'\n';


    

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