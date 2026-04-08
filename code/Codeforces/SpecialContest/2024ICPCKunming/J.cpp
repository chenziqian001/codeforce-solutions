#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    vector<int> v=p;
    sort(v.begin(),v.end());


    if(v==p){
        cout<<"Alice"<<'\n';
        return;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(v[i]!=p[i]);
    }


    if(n==2){
        cout<<"Alice"<<'\n';
        return;
    }
    if(n>=4){
        if(s=="Alice" && cnt==2){
            cout<<s<<'\n';
        }
        else cout<<"Bob"<<'\n';
        return;
    }

    if(cnt==2){
        cout<<s<<'\n';
    }
    else{
        if(s=="Alice"){
            cout<<"Bob"<<'\n';
        }
        else cout<<"Alice"<<'\n';
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

