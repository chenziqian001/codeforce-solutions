#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n,k;
    long long x;
    cin>>n>>k>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> prefix(n+1,0);
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+a[i-1];
    if(prefix[n]*k<x){
        cout<<0<<'\n';
        return;
    }
    

    long long target=k*prefix[n]-x;
    long long numb=target/prefix[n];
    long long remain=target%prefix[n];
    

    int pos;
    for(int i=0;i<=n;i++){
        if(prefix[i]>remain){
            pos=i;
            break;
        }
    }    
    cout<<numb*n+pos<<'\n';
    return;
    

}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}