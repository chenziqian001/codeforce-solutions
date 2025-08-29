#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt0=0;
    for(int i=0;i<n;i++){
        cnt0+=(s[i]=='0');
        if(i>=k){
            cnt0-=(s[max(0,i-k)]=='0');
        }
        if(cnt0==0 && i>=(k-1)){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
    int init=n;
    vector<int> res(n);
    for(int i=0;i<n;i++){
        if(s[i]=='0') res[i]=init--;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1') res[i]=init--;
    }
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<'\n';

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}