#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int> xdir,ydir,slope1,slope2;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        xdir[x]++;
        ydir[y]++;
        slope1[x-y]++;
        slope2[x+y]++;
    }
    long long res=0;
    for(auto p:xdir){
        res+=1LL*p.second*(p.second-1);
    }
    for(auto p:ydir){
        res+=1LL*p.second*(p.second-1);
    }
    for(auto p:slope1){
        res+=1LL*p.second*(p.second-1);
    }
    for(auto p:slope2){
        res+=1LL*p.second*(p.second-1);
    }
    cout<<res<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}