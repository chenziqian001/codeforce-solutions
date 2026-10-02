#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxi=*max_element(a.begin()+1,a.end());
    int mini=*min_element(a.begin()+1,a.end());
    int avg=accumulate(a.begin(),a.end(),0LL)/n;
    cout<<maxi<<" "<<mini<<" "<<avg<<'\n'; 
    bool ok=false;
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(a[i]>2*avg){
            res.push_back(i);
            ok=true;
        }
    }
    if(!ok){
        cout<<"Normal";
    }
    else{
        for(int i=0;i<res.size();i++){
            cout<<res[i];
            if(i!=res.size()-1){
                cout<<" ";
            }
        }
    }
    
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