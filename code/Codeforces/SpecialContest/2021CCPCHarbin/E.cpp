#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
#define int long long

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=-1;
    for(int i=0;i<n;i++){
        if(i<=60){
            if(a[i]==qp(2,i)) continue;
            res=qp(2,i)-a[i];
            if(res<=0||a[i]>=res){
                cout<<-1<<'\n';
                return;
            }
            for(int j=i+1;j<n;j++){
                if(a[j]!=(a[j-1]*2)%res){
                    cout<<-1<<'\n';
                    return;
                }
            }
            cout<<res<<'\n';
            return;
        }
    }
    cout<<-1<<'\n'; 
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



