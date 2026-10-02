#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> re(k);
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            re[i%k]++;
        }
    }
    for(int i=0;i<k;i++){
        if((re[i]%2)==1){
            cout<<"NO"<<'\n';
            return;
        }

    }
    cout<<"YES"<<'\n';


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