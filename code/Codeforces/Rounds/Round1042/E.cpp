#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=n-1;i>=0;i--){
        if(a[i]==b[i]) continue;

        if(i==n-1){
            cout<<"NO"<<'\n';
            return;
        }


        if(((a[i]^a[i+1])!=b[i]) && ((a[i]^b[i+1])!=b[i])){
            cout<<"NO"<<'\n';
            return;
        }        
    }

    cout<<"YES"<<'\n';

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