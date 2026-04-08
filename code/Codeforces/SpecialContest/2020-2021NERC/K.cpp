#include<bits/stdc++.h>
using namespace std;
#define int long long





void solve(){
    int n;
    cin>>n;
    vector<int> p(2*n+1);
    for(int i=1;i<=2*n;i++){
        cin>>p[i];
    }

    if(n%2==0){
        int tp=p[1]>n?1:0;
        for(int i=1;i<n;i++){
            if((tp==0 && p[i]>n) || (tp==1 && p[i]<=n)){
                cout<<-1<<'\n';
                return;
            }
        }
        for(int i=3;i<=2*n;i+=2){
            if((p[2]-p[1]>0 && p[i+1]-p[i]<0) ||(p[2]-p[1]<0 && p[i+1]-p[i]>0) ){
                cout<<-1<<'\n';
                return;
            }
        }
        int res=0;
        if(p[1]>n) res++;
        if(p[1]>p[2]) res++;
        cout<<res<<'\n';
        return;
    }

    int res=0;
    int f=0;
    while(p[1]!=1){
        if(f==0){
            for(int i=1;i<=2*n;i+=2){
                swap(p[i],p[i+1]);
            }
        }
        else{
            for(int i=1;i<=n;i++){
                swap(p[i],p[n+i]);
            }
        }
        res++;
        f^=1;
    }

    for(int i=1;i<=n*2;i++){
        if(p[i]!=i){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<min(res,2*n-res)<<'\n';    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}