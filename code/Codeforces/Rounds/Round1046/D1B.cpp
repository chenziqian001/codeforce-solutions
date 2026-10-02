#include<bits/stdc++.h>
using namespace std;
#define int long long

int ask(char c,int k){
    cout<<"? "<<c<<" "<<k<<endl;
    int res;
    cin>>res;
    if(res==-1) exit(0);
    return res;
}

struct node{int x,y;};

void solve(){
    int n;
    cin>>n;
    vector<node> a(n);
    int M1=-3e18,M2=3e18;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        M1=max(M1,a[i].x+a[i].y);
        M2=min(M2,a[i].x-a[i].y);
    }
    
    ask('R',1000000000);
    ask('R',1000000000);
    ask('U',1000000000);
    int d1=ask('U',1000000000);
    
    ask('L',1000000000);
    ask('L',1000000000);
    ask('L',1000000000);
    int d2=ask('L',1000000000);
    
    int S=d1+M1-4000000000LL;
    int D=d2-M2-4000000000LL;
    int X=(S-D)/2;
    int Y=(S+D)/2;
    cout<<"! "<<X<<" "<<Y<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();   
    return 0;
}