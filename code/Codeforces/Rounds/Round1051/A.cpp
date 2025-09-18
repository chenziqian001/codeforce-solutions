#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int pos=-1;
    for(int i=0;i<n;i++){
        if(a[i]==n){
            pos=i;
            break;
        }
    }
    bool ok=true;
    for(int i=0;i<pos;i++){
        if(a[i]>a[i+1]){
            ok=false;
            break;
        }
    }
    for(int i=n-1;i>pos;i--){
        if(a[i]>a[i-1]){
            ok=false;
            break;
        }
    }
    if(ok){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}