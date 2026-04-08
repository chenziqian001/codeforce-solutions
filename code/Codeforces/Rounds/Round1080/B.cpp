#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) b[i]=i;


    vector<bool> vis(n+1,false);
    for(int i=1;i<=n/2;i++){
        vector<int> tmp;
        vector<int> pos;
        for(int j=i;j<=n;j*=2){
            tmp.push_back(a[j]);
            pos.push_back(j);
            
        }
        
        sort(tmp.begin(),tmp.end());
        for(int j=0;j<pos.size();j++){
            a[pos[j]]=tmp[j];
        }
    }


    if(a==b){
        cout<<"YES"<<'\n';

    }
    else cout<<"NO"<<'\n';
   
     
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
