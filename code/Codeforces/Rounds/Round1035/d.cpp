#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    int px,py,qx,qy;
    cin>>px>>py>>qx>>qy;
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long tt=0;
    long long maxi=a.back();
    double x=abs(px-qx);
    double y=abs(py-qy);
    double dist_sq=sqrt(x*x+y*y);
    for(int num:a){
        tt+=1LL*num;
    }
    
    if((px==qx)&&(py==qy)){
        if((tt%2==1)||(n==1)){
            cout<<"NO"<<'\n';
        }
        else{
            if(maxi>tt/2){
                cout<<"NO"<<'\n';
                return;
            }
            vector<bool> dp(tt/2+1);
            dp[0]=true;
            for(int i=0;i<n;i++){
                for(int j=tt/2;j>=a[i];j--){
                    dp[j]=dp[j]|dp[j-a[i]];
                }
            }
            if(dp[tt/2]){
                cout<<"YES"<<'\n';
            }
            else cout<<"NO"<<'\n';
        }
        
    }
    else{
        double t=tt;
        if(dist_sq<=t&&(maxi*2-t)<=dist_sq){
            cout<<"yes"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
    }
}
 
 
int main(){
    int t;
    cin>>t;
    while(t--) solve();
 
    system("pause");
    return 0;
}