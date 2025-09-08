#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    k=min(k,2+(k%2));
    long long sum=0;
    while(k--){
        vector<int> cnt(N,0);
        sum=0;
        for(int i=0;i<n;i++) cnt[a[i]]++;
        int mex=0;
        while(cnt[mex]) mex++;
        for(int i=0;i<n;i++){
            if(a[i]<mex){
                if(cnt[a[i]]>1) a[i]=mex;
            }
            else a[i]=mex;
            sum+=a[i];
        } 
    }
    cout<<sum<<'\n';
} 


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}