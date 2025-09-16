#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    for(int i=1;i<n;i++){
        int s1=pre[i]%3;
        for(int j=i+1;j<n;j++){
            int s2=(pre[j]-pre[i])%3;
            int s3=(sum-pre[j])%3;
            if((s1==s2 && s1==s3)||(s1!=s2 && s1!=s3 && s2!=s3)){
                cout<<i<<" "<<j<<'\n';
                return;
            }
        }
    }
    cout<<0<<" "<<0<<'\n';



}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}