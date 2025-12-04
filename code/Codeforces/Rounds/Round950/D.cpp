#include<bits/stdc++.h>
using namespace std;
 
int check(int skip,vector<int> a){
    vector<int> b;
    for(int i=0;i<a.size();i++){
        if(i!=skip){
            b.push_back(a[i]);
        }
    }
    int n=b.size();
    vector<int> seq(n-1);
    for(int i=0;i<n-1;i++){
        seq[i]=__gcd(b[i],b[i+1]);
    }
    for(int i=1;i<n-1;i++){
        if(seq[i]<seq[i-1]){
            return 0;
        }
    }
    return 1;
}



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> seq(n-1);
    for(int i=0;i<n-1;i++){
        seq[i]=__gcd(a[i],a[i+1]);
    }
    vector<int> tmp;
    
    bool ok=true;
    for(int i=1;i<n-1;i++){
        if(seq[i]<seq[i-1]){
            tmp.push_back(i-1);
            tmp.push_back(i);
            tmp.push_back(i+1);
            ok=false;
        }
    }
    if(ok){
        cout<<"YES"<<'\n';
        return;  
    }

    int res=0;
    for(int i=0;i<3;i++){
        res|=check(tmp[i],a);
    }

    if(res){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
    



}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}