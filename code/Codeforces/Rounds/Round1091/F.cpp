#include<bits/stdc++.h>
using namespace std;
#define int long long


int count(int s,int k){
    if(k<0) return 0;
    int res=0;
    int vali=true;

    for(int i=19;i>=0;i--){
        int x=((s>>i)&1);
        int y=((k>>i)&1);
        if(y==1){
            int cnt=i-__builtin_popcountll(s&((1LL<<i)-1));
            res+=(1LL<<cnt);
        
            if(x==1){
                vali=false;
                break;
            }
        }
    }
    if(vali) res++;
    return res;
}



void solve(){
    int x1,x2;
    cin>>x1>>x2;
    if(x1>x2){
        cout<<x1<<" "<<x1<<'\n';
        return;
    }

    int mini=-1;
    int bst=0;


    for(int s=0;s<x1;s++){
        int k=(x2-s-1)/2;
        int cur=0;
        if(k>=0){
            int val=count(s,k);
            cur=val*(1LL<<__builtin_popcountll(s));
        }
        if(mini==-1 || cur<mini){
            mini=cur;
            bst=s;
        }
    }
    cout<<bst+1<<" "<<x1<<'\n';
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
