#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    int res=0;
    int lst=-1;
    int c=0;
    for(auto [x,y]:cnt){
        if(lst+1!=x) c=0;
        res+=max(0LL,y-c);
        lst=x,c=y;
    }
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