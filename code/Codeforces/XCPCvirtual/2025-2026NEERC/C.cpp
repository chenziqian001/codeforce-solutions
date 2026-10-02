#include<bits/stdc++.h>
using namespace std;
#define int long long

int get(string s){
    int res=0;
    for(int i=0;i<8;i++){
        if(s[i]=='1'){
            res+=(1LL<<(7-i));
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    if(n==0){
        cout<<0<<'\n';
        return;
    }
    vector<int> a;
    while(n){
        a.push_back(n&(127));
        n>>=7;
    }
    for(int i=a.size()-1;i>=0;i--){
        if(i!=0) cout<<(a[i]|(128))<<" ";
        else cout<<a[i]<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}