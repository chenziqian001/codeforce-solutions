#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            int sum=i*n+j;
            if(j!=1) sum+=i*n+j-1;
            if(j!=n) sum+=i*n+j+1;
            if(i!=0) sum+=i*n+j-n;
            if(i!=n-1) sum+=i*n+j+n;
            mx=max(mx,sum);
        }
    }

    cout<<mx<<'\n';


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