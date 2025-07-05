#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(n+2);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int> diff(n+2);
    for(int i=0;i<n+2;i++){
        diff[cnt[i]]++;
        diff[n-i+1]--;
        if(cnt[i]==0){
            break;
        }
    }
    vector<int> ans(n+1);
    for(int k=0;k<=n;k++){
        ans[k]=(k?ans[k-1]:0)+diff[k];
        cout<<ans[k]<<" ";

    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
