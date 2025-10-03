#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve1(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    vector<int> top(n+1);
    vector<int> bot(n+1);
    int res=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            top[i]=bot[i-1]+1;
        }
        else{
            bot[i]=bot[i-1]+(n-i);
            top[i]=top[i-1]+(i-1);
        }
        res=max({res,bot[i],top[i]});
    }

    cout<<res<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve1();
    system("pause");
    return 0;
}
