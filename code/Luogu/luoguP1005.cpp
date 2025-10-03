#include<bits/stdc++.h>
using namespace  std;
using i28=__int128_t;



string toString(__int128_t x){
    if(x == 0) return "0";
    string s;
    while(x > 0){
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}



i28 qpow(int a,int n){
    i28 res=1,base=a;
    while(n){
        if(n&1) res=(res*base);
        base=base*base;
        n>>=1;
    }
    return res;
}

i28 get(const vector<int> &a){
    int len=a.size();
    vector<vector<i28>> dp(len,vector<i28>(len));
    for(int i=1;i<=len;i++){
        for(int j=0;j<len-i+1;j++){
            int k=j+i-1;
            if(i==1) dp[j][j]=(i28)a[j]*qpow(2,len);
            else{
                int p=len-i+1;
                dp[j][k]=max(dp[j+1][k]+(i28)a[j]*qpow(2,p),dp[j][k-1]+(i28)a[k]*qpow(2,p));
            }
        }
    }

    return dp[0][len-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    i28 res=0;
    for(int i=0;i<n;i++){
        vector<int> a(m);
        for(int i=0;i<m;i++) cin>>a[i];
        i28 val=get(a);
        res+=val;
    }    
    string ans=toString(res);
    cout<<ans<<'\n';
    return 0;
}