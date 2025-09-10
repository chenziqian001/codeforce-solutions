#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<a[0]*m<<'\n';
        return;
    }
    long long res=0;
    sort(a.rbegin(),a.rend());
    long long time=m;
    for(int i=0;i<n;i++){
        if(time && (i==n-1)){
            res+=time*a[i];
            break;
        }
        res+=time*a[i];
        time--;
        if(time==0) break;
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