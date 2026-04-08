#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=s[i]-'0';
    }
    string res;
    int cur=0;
    for(int i=n-1;i>=0;i--){
        cur+=sum;
        res+=char(cur%10+'0');
        cur/=10;
        sum-=s[i]-'0';
    }
    while(cur>0){
        res+=char(cur%10+'0');
        cur/=10;
    }
    while(res.size()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(),res.end());
    cout<<res<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

