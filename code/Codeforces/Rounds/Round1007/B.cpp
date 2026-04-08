#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int n){
    int x=sqrt(n);
    return n==x*x;
}


void solve(){
    int n;
    cin>>n;

    int sum=(n+1)*n/2;
    if(check(sum)){
        cout<<-1<<'\n';
        return;
    }

    vector<int> res(n);
    iota(res.begin(),res.end(),1);
    for(int i=1;i<n;i++){
        if(check(i*(i+1)/2)){
            swap(res[i],res[i-1]);
        }
    } 

    for(int x:res){
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