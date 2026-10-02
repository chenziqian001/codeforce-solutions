#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long


void solve(){
    int n;
    cin>>n;
    int tt=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        tt^=a[i];
    }
    if(!tt){
        cout<<"DRAW"<<'\n';
        return;
    }
    for(int k=30;k>=0;k--){
        if(tt>>k&1){
            int x=0,y=0;
            for(int i=0;i<n;i++){
                if(a[i]>>k&1) x++;
                else y++;
            }
            if(x%4==1){
                cout<<"WIN"<<'\n';
            }
            else{
                if(y%2==0){
                    cout<<"LOSE"<<'\n';
                }
                else{
                    cout<<"WIN"<<'\n';
                }
            }
            return;
        }
    }
    cout<<"FUCK"<<'\n';



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