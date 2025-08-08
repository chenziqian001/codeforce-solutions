#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int res=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int l=0,r=0;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]) l++;
        }
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]) r++;
        }
        res+=min(l,r);
    }
    cout<<res<<'\n';
    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}