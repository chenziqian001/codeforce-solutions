#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int p=0,m=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+') p++;
        else m++;
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(p==m){
            cout<<"YES"<<'\n';
            continue;
        }
        if(a==b){
            cout<<"NO"<<'\n';
            continue;
        }
        int num=b*(m-p);
        int den=a-b;
        if(num%den!=0){
            cout<<"NO"<<'\n';
            continue;
        }
        int d=num/den;
        if(d>=-m && d<=p){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}