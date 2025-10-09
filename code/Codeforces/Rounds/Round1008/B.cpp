#include<bits/stdc++.h>
using namespace std;
void solve(){
    int even=0,odd=0;
    for(int i=0;i<30;i++){
        if(i%2==0) even|=(1<<i);
        else odd|=(1<<i);
    }
    int a[2];
    cout<<even<<'\n';
    cin>>a[0];
    cout<<odd<<'\n';
    cin>>a[1];


    a[0]-=even*2;
    a[1]-=odd*2;
    swap(a[0],a[1]);

    int cnt[30] {};
    for(int i=0;i<30;i++){
        if(a[i%2]>>i&1) cnt[i]=1;
        else if(a[i%2]>>(i+1)&1) cnt[i]=2;
    }
    int res=0;
    cout<<"!"<<'\n';
    int m;
    cin>>m;
    
    for(int i=0;i<30;i++){
        if(m&(1<<i)){
            res+=(2<<i);
        }
        else{
            res+=(cnt[i]<<i);
        }
    }
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}



