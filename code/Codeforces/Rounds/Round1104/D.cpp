#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    int cnt[3]={0};
    cnt[0]=1;

    int cur=0;
    for(int i=0;i<n;i++){
        int x=(s[i]=='0')?1:2;
        cur=(cur+x)%3;
        res+=(i+1)-cnt[cur];
        cnt[cur]++;
    }
    int len=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            len++;
        }
        else{
            int m=(len-1)/2;
            res-=m*(len-m-1);
            len=1;
        }
    }
    int m=(len-1)/2;
    res-=m*(len-m-1);
    cout<<res<<'\n';
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

