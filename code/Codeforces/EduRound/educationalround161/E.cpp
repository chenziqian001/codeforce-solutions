#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x;
    cin>>x;

    int l=0,h=0;
    vector<int> res;


    function<void(int)> get=[&](int x){
        if(x==1) return;
        if(x%2==1){
            get(x-1);
            res.push_back(--l);
        }
        else{
            get(x/2);
            res.push_back(++h);
        }
    };
    get(x);

    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<'\n';


    
    
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