#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=-1e18;
const int N=1e13;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    vector<int> b(n,inf);

    b[0]=c[0];
    for(int i=1;i<n;i++){
        if(c[i]>c[i-1]) b[i]=c[i];
        else if(c[i]<c[i-1]){
            cout<<"NO"<<'\n';
            return;
        }
    }

    for(int i=n-1;i>=1;i--){
        if(b[i]!=inf && s[i]=='1'){
            if(b[i-1]!=inf && b[i-1]!=b[i]-a[i]){
                cout<<"NO"<<'\n';
                return;
            }
            b[i-1]=b[i]-a[i];
        }
    }

    for(int i=0;i<n;i++){
        if(b[i]==inf){
            if(s[i]=='1') b[i]=b[i-1]+a[i];
            else b[i]=-N;
        }
    }
    int mx=-N;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(i==0 && b[i]!=a[i]){
                cout<<"NO"<<'\n';
                return;
            }
            if(i>0 && b[i]-b[i-1]!=a[i]){
                cout<<"NO"<<'\n';
                return;
            }
        }
        mx=max(mx,b[i]);
        if(mx!=c[i]){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
    a[0]=b[0];
    for(int i=1;i<n;i++){
        a[i]=b[i]-b[i-1];
    }
    for(int x:a){
        cout<<x<<" ";
    }
    cout<<'\n';
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