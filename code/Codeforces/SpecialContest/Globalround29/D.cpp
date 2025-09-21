#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end()){
            mp[a[i]]=1;
        }
        else mp[a[i]]++;
    }
    vector<pair<int,int>> b;
    for(auto m:mp){
        b.emplace_back(m.second,m.first);
    }
    sort(b.rbegin(),b.rend(),[&](auto x,auto y){
        if(x.first==y.first){
            return x.second%2>y.second%2;
        }
        else{
            return x.first<y.first;

        }
    });
    long long v1=0,v2=0;
    int rd=1;
    for(auto p:b){
        int big=p.second;
        if(big<=0){
            continue;
        }
        if(big%2==0){
            v1+=p.first*big/2;
            v2+=p.first*big/2;
        }
        else{
            if(rd==1){
                v1+=p.first*(big/2+1);
                v2+=p.first*(big/2);
                
            }
            else{
                v2+=p.first*(big/2+1);
                v1+=p.first*(big/2);
            }
            rd=1-rd;
        }
    }
    cout<<v1<<" "<<v2<<'\n';
    
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}


