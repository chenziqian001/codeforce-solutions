#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    vector<int> b;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i%2==1){
            a.push_back(x);
        }
        else{
            b.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ca=0,cb=0;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(x%2==1) ca++;
        else cb++;
    }
    int sa=accumulate(a.begin(),a.end(),0LL);
    int sb=accumulate(b.begin(),b.end(),0LL);
    if(!a.empty() && a.back()<0 && ca>0){
        sa-=a.back();
    }
    if(!b.empty() && b.back()<0 && cb>0){
        sb-=b.back();
    }
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<0 || ca<=0) break;
        else{
            sa-=a[i];
            ca--;
        }
    }
    for(int i=b.size()-1;i>=0;i--){
        if(b[i]<0 || cb<=0) break;
        else{
            sb-=b[i];
            cb--;
        }
    }
    


    cout<<sa+sb<<'\n';

 

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