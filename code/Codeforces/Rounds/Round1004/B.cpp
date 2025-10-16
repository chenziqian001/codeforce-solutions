#include<bits/stdc++.h>
using namespace std;
int check(vector<int> a){
    int m=a.size();
    vector<int> sufmex(m);
    vector<int> cnt(m+1); 
    int mex=0;
    for(int i=m-1;i>=1;i--){
        if(a[i]<=m) cnt[a[i]]++;
        while(cnt[mex]) mex++;
        sufmex[i]=mex; 
    }
    int mini=a[0];
    for(int i=0;i<m-1;i++){
        mini=min(mini,a[i]);
        if(mini<sufmex[i+1]) return 0;
    }
    return 1;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int cnt=0;
    int cnt0=0;
    vector<int> b;
    bool ok=true;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cnt0++;
            if(ok){
                b.push_back(0);
            }
            ok=false;
        }
        else{
            cnt++;
            b.push_back(a[i]);
        }

    }
    if(cnt0==0){
        cout<<cnt<<'\n';
    }
    else{
        cout<<cnt+check(b)<<'\n';    
    } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}