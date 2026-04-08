#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    cin>>s;

    string res;
    int cnt=0;
    int mask=0;

    for(int i=0;i<m;i++){
        mask|=(1LL<<(s[i]-'a'));
        if(mask==((1<<k)-1)){
            cnt++;
            res+=s[i];
            mask=0;
        }
    }


    if(cnt>=n){
        cout<<"YES"<<'\n';
        return;
    }
    else{
        cout<<"NO"<<'\n';
    }

    char miss='a';
    for(int i=0;i<k; i++){
        if(!(mask>>i&1)){
            miss=miss+i;
            break;
        }
    }
    while(res.size()<n){
        res+=miss;
    }

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
