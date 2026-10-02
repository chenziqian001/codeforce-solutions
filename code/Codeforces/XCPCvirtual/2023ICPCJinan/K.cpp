#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]-=i;
    }
    multiset<int> L,R;
    int sumL=0,sumR=0;
    auto balance=[&](){
        while(L.size()>R.size()+1){
            int val=*L.rbegin();
            L.erase(prev(L.end()));
            sumL-=val;
            sumR+=val;
            R.insert(val);
        }
        while(L.size()<R.size()){
            int val=*R.begin();
            R.erase(R.begin());
            sumR-=val;
            L.insert(val);
            sumL+=val;
        }
    };
    auto add=[&](int x){
        if(L.empty() || x<=*L.rbegin()){
            L.insert(x);
            sumL+=x;
        }
        else{
            R.insert(x);
            sumR+=x;
        }
        balance();
    };

    auto del=[&](int x){
        auto it=L.find(x);
        if(it!=L.end()){
            L.erase(it);
            sumL-=x;
        }
        else{
            R.erase(R.find(x));
            sumR-=x;
        }
        balance();
    };
    auto get=[&](){
        if(L.empty()) return 0LL;
        int mid=*L.rbegin();
        return (sumR-mid*(int)R.size())+(mid*(int)L.size()-sumL);
    };
    int l=0,res=0;
    for(int r=0;r<n;r++){
        add(a[r]);
        while(get()>k){
            del(a[l]);
            l++;
        }
        res=max(res,r-l+1);
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
