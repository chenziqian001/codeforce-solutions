#include<bits/stdc++.h>
using namespace std;

double len(int x1,int y1,int x2,int y2){
    double x=abs(x1-x2);
    double y=abs(y1-y2);
    return sqrt(x*x+y*y);
}


void solve(){
    int n;
    cin>>n;
    int px,py,qx,qy;
    cin>>px>>py>>qx>>qy;
    double sum=0;
    vector<double> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    double m=a.back();
    double l=len(px,py,qx,qy);
    if(l<=sum&&(m-(sum-m))<=l){
        cout<<"yes"<<'\n';
    }
    else{
        cout<<"no"<<'\n';
    }
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();

    system("pause");
    return 0;
}