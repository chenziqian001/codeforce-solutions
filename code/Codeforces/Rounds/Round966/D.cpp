#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> pre(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pre[i]=pre[i-1]+x;
    }
    string s;
    cin>>s;
    s=" "+s;
    int l=1,r=n;
    long long res=0;
    while(l<r){
        if(s[l]=='L' && s[r]=='R'){
            res+=pre[r]-pre[l-1];
            l++,r--;
        }
        else if(s[l]=='L') r--;
        else if(s[r]=='R') l++;
        else{
            l++,r--;
        }
    }
    cout<<res<<'\n';

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