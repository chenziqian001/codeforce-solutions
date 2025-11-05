#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> op(n);
    while(*max_element(a.begin(),a.end())>=2){
        vector<int> tmp(n);
        for(int i=0;i<n;i++){
            tmp[i]=a[i]/2;
            op[i]+=tmp[i];
        }
        for(int i=0;i<n;i++){
            a[i]-=tmp[i]*2;
            a[(i+1)%n]+=tmp[i];
        }
    }
    vector<int> final(n,a[0]);
    if(a!=final){
        cout<<-1<<'\n';
    }
    else cout<<accumulate(op.begin(),op.end(),0LL)-*min_element(op.begin(),op.end())*n<<'\n';

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
