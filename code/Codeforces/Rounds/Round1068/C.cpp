#include <bits/stdc++.h>
using namespace std;
#define int long long

set<int> s;
set<int> ss;



void solve(){
    s.clear();
    ss.clear();
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
        ss.insert(x);
    }
    vector<int> res;

    while(!s.empty()){
        int v=*s.begin();
        res.push_back(v);
        for(int x=v;x<=k;x+=v){
            if(!ss.count(x)){
                cout<<-1<<'\n';
                return;
            }
            auto it=s.find(x);
            if(it!=s.end()) s.erase(it);
        }
        
    }


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
