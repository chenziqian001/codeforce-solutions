#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,j,k;
    cin>>n>>j>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int jj=a[j-1];
    sort(a.begin(),a.end());
    int maxi=a[n-1];
    if((jj!=maxi&&k!=1)||(jj==maxi)){
        cout<<"YES"<<'\n';
    }   
    else{
        cout<<"NO"<<'\n';
    }



}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
