#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int mini=100;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mini=min(mini,a[i]);
    }
    int tg=0;
    for(int i=mini;i>=0;i--){
        int s=0,mx=0;
        for(int j=0;j<n;j++){
            mx=max(mx,a[j]-i);
            s+=a[j]-i;
        }
        if(mx*2<=s){
            tg=i;
            break;
        }
    }
    vector<string> res;
    while(1){
        int s=0;
        for(int i=0;i<n;i++){
            if(a[i]>tg)s+=a[i]-tg;
        }
        if(s==0)break;
        int k=2;
        if(s%2==1&&n>=3)k=3;
        string S(n,'0');
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)v[i]={a[i],i};
        sort(v.rbegin(),v.rend());
        for(int i=0;i<k;i++){
            int id=v[i].second;
            S[id]='1';
            if(a[id])a[id]--;
        }
        res.push_back(S);
    }
    cout<<tg<<'\n';
    cout<<res.size()<<'\n';
    for(string S:res)cout<<S<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}
 




