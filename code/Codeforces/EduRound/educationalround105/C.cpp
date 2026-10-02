#include<bits/stdc++.h>
using namespace std;
#define int long long






int get(vector<int> &a,vector<int> &b){
    int n=a.size();
    int m=b.size();
    if(n==0 || m==0) return 0;
    vector<int> suf(n+1);
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1];
        if(binary_search(b.begin(),b.end(),a[i])){
            suf[i]++;
        }
    }

    int res=suf[0];
    for(int j=0;j<m;j++){
        int cnt=upper_bound(a.begin(),a.end(),b[j])-a.begin();
        if(cnt==0) continue;
        int l=b[j]-cnt+1;
        int r=b[j];
        int match=(b.begin()+j+1)-lower_bound(b.begin(), b.end(),l);
        res=max(res,match+suf[cnt]);
    }

    return res;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    vector<int> posa,posb;
    vector<int> nega,negb;
    for(int x:a){
        if(x>=0){
            posa.push_back(x);
        }
        else{
            nega.push_back(-x);
        }
    }
    for(int x:b){
        if(x>=0){
            posb.push_back(x);
        }
        else{
            negb.push_back(-x);
        }
    }
    reverse(nega.begin(),nega.end());
    reverse(negb.begin(),negb.end());
    cout<<get(posa,posb)+get(nega,negb)<<'\n';

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