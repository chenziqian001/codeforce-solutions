#include<bits/stdc++.h>
using namespace std;
#define int long long

int get_down(int a,int b){
    int res=a;
    for(int i=30;i>=0;i--){
        if(res>>i&1 && b>>i&1){
            res^=(1LL<<i);
            res|=((1LL<<i)-1);
        }
    }
    return res;
}

int get_up(int a,int b){
    for(int i=0;i<=30;i++){
        if(a>>i&1 && b>>i&1){
            a+=(1LL<<i);
            a&=~((1LL<<(i+1))-1);
        }
    }
    return a;
}

void solve(){
    int x,y;
    cin>>x>>y;
    
    int p1=get_down(x,y),q1=y;
    int p2=get_up(x,y),q2=y;
    int p3=x,q3=get_down(y,x);
    int p4=x,q4=get_up(y,x);
    
    int ansp=p1,ansq=q1;
    int min_cost=abs(x-p1)+abs(y-q1);
    
    auto update=[&](int p,int q){
        int cost=abs(x-p)+abs(y-q);
        if(cost<min_cost){
            min_cost=cost;
            ansp=p;
            ansq=q;
        }
    };
    
    update(p2,q2);
    update(p3,q3);
    update(p4,q4);
    
    cout<<ansp<<" "<<ansq<<'\n';
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
