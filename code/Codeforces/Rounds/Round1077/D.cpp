#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int x,y;
    cin>>x>>y;
    int ans=x+y;
    int p=0,q=0;
    
    for(int i=0;i<30;i++){
        for(int j=0;j<=30;j++){
            int a=x>>i<<i;
            int b=y>>j<<j;
            for(auto P:{a,a+(1<<i),a+(1<<i)-1}){
                for(auto Q:{b,b+(1<<j),b+(1<<j)-1}){
                    Q-=P&Q;
                    int cost=abs(x-P)+abs(y-Q);
                    if(cost<ans){
                        ans=cost;
                        p=P;
                        q=Q;
                    }
                }
            }

        }
    }

    cout<<p<<" "<<q<<'\n';

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