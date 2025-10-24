#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
const int mx=1e6+10;
int a[N];
int b[N];
int cnt[mx];
int n;
bool check(int k){
    for(int i=0;i<n;i++){
        cnt[a[i]%k]++;
    }
    for(int i=0;i<n;i++){
        if(--cnt[b[i]]<0){
            cnt[b[i]]=0;
            for(int j=0;j<n;j++){
                cnt[a[j]%k]=0;
            }
            return false;
        }
    }
    return true;
}


void solve(){
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[i]=x;sum+=x;
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        b[i]=x;sum-=x;
    }
    if(sum==0){
        if(check(1e7)) cout<<1000001<<'\n';
        else cout<<-1<<'\n';
        return;
    }
    for(int i=1;i*i<=sum;i++){
        if(sum%i) continue;
        if(check(i)){
            cout<<i<<'\n';
            return;
        }
        if(i<sum && check(sum/i)){
            cout<<sum/i<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}
signed main(){
    int t;
    cin>>t;
    
    while(t--) solve();
    system("pause");
    return 0;
}
