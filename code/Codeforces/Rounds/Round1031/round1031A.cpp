#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<numeric>
using namespace std;


void solve(){
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;
    if(x>y){
        swap(x,y);
        swap(a,b);
    }
    int ans=0;
    if(k>=a){
        int gapa=k-a;
        ans+=((gapa/x)+1);
        k-=x*((gapa/x)+1);
    }
    if(k>=b){
        int gapb=k-b;
        ans+=((gapb/y)+1);
        k-=y*((gapb/y)+1);
    }
    cout<<ans<<'\n';
    
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}