#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    char c=s[0];
    string res;
    for(int i=1;i<n;i++){
        if(s[i]==c){
            res+=c;
            if(i+1<n){
                c=s[i+1];
                i++;
            }
        }
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