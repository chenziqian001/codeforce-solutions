#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i][1];
        if(a[i][0]>a[i][1]){
            swap(a[i][0],a[i][1]);
            cnt++;
        }
    }
    sort(a.begin(),a.end());
    bool ok=true;
    bool canswap=false;
    for(int i=1;i<n;i++){
        if(a[i-1][1]<a[i][0]){
            if(i%2==1) canswap=true;
        }
        else if(a[i-1][1]>a[i][1]) ok=false;
    }
    if(ok && (canswap || cnt%2==0 || n%2==1)){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}



