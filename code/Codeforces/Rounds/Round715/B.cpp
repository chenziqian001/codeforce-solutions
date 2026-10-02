#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        if(s[i]=='T') a.push_back(i);
        else b.push_back(i);
    }
    if(a.size()!=2*b.size()){
        cout<<"NO"<<'\n';
        return;
    }
    for(int i=0;i<b.size();i++){
        if(b[i]<a[i] || b[i]>a[i+b.size()]){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}