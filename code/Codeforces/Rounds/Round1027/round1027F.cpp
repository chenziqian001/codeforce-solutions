#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int get_ans(int x,int k){
    if(x==1) return 0;
    vector<int> fac;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            fac.push_back(i);
            if(x/i!=i) fac.push_back(x/i);
        }
    }
    sort(fac.begin(),fac.end());
    int n=fac.size();

    vector<int> dp(n,100);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(fac[i]/fac[j]>k) break;
            if(fac[i]%fac[j]==0){
                dp[i]=min(dp[i],dp[j]+1);  
            }            
        }
    }
    return dp[n-1]==100?-1:dp[n-1];
}

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    int g=gcd(x,y);
    x/=g;
    y/=g;
    int ax=get_ans(x,k);
    int ay=get_ans(y,k);
    if(ax==-1||ay==-1){
        cout<<-1<<'\n';
        return;
    }
    else cout<<ax+ay<<'\n';
    return;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    
    return 0;
}
