#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    if(n<=60 && (1LL<<(n-1))<k){
        cout<<-1<<'\n';
        return;
    }
    k--;
    vector<int> d;
    while(k){
        d.push_back(k&1);
        k>>=1;
    }
    vector<int> res(n);
    while(d.size()<n-1) d.push_back(0);
    reverse(d.begin(),d.end());
    int l=0,r=n-1;
    int num=1;
    for(int dir:d){
        if(dir){
            res[r--]=num++;
        }
        else{
            res[l++]=num++;
        }
    }

    for(int i=0;i<n;i++){
        if(res[i]==0){
            cout<<n<<" ";
        }
        else{
            cout<<res[i]<<" ";
        }
    }
    cout<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

 

