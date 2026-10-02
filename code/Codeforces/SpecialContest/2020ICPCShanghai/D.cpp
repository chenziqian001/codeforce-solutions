#include<bits/stdc++.h>
using namespace std;
#define int long long

double get(double p,double v,double t){
    if(t*v<p) return -1;
    return max(t*v-p,(t*v+p)/2);
}

void solve(){
    double n,p1,v1,p2,v2;
    cin>>n>>p1>>v1>>p2>>v2;


    if(p1>p2){
        swap(p1,p2);
        swap(v1,v2);
    }

    
    double l=0,r=2e9;
    for(int i=0;i<100;i++){
        double mid=(l+r)/2;
        double l1=get(p1,v1,mid);
        double r1=get(n-p1,v1,mid);
        double l2=get(p2,v2,mid);
        double r2=get(n-p2,v2,mid);
        if(l1>=n||l2>=n||(l1>=0&&r2>=0&&l1+r2>=n)||(l2>=0&&r1>=0&&l2+r1>=n)) r=mid;
        else l=mid;
    }

    cout<<fixed<<setprecision(9)<<r<<'\n';
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


