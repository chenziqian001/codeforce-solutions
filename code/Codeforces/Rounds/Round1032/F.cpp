#include<bits/stdc++.h>
using namespace std;
long long n,s,x;

void solve(){
    cin>>n>>s>>x;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<long long> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    map<long long,int> cnt;
    int l=1;
    long long res=0; 
    for(int r=1;r<=n;r++){
        if(a[r]>x){
            cnt.clear();
            l=r+1;
        }
        else if(a[r]==x){
            while(l<=r){
                cnt[pre[l-1]]++;
                l++;
            }
            
        }
        res+=cnt[pre[r]-s];
    
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