#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> p1(n+1);
    vector<int> p2(n+1);
    for(int i=0;i<n;i++){
        p1[i+1]=p1[i]+(s[i]=='4');
        p2[i+1]=p2[i]+(s[i]=='8');
    }
    while(q--){
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        x=abs(x);
        y=abs(y);
        int len = r-l+1;
        if(x<=len && y<=len && x+y<=len+p2[r]-p2[l-1]){
            cout<<"YES"<<'\n';
            continue;
        }
        cout<<"NO"<<'\n';
    }
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}