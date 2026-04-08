#include<bits/stdc++.h>
using namespace std;
#define int long long

int get(multiset<int> x,multiset<int> y,int k){
    x.insert(k);
    int res=0;
    int n=x.size();
    for(int i=0;i<n;i++){
        while(!y.empty() && *y.begin()<=*x.begin()){
            y.erase(y.begin());
        }
        if(y.empty()){
            break;
        }

        y.erase(y.begin());
        x.erase(x.begin());;
        res++;
    }
    return n-res;
}





void solve(){
    int n,m;
    cin>>n>>m;
    multiset<int> a,b;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.insert(x);
    }
    int x=get(a,b,1);
    int l=1,r=m;
    int res=m+1;
    while(l<=r){
        int mid=(l+r)/2;
        if(get(a,b,mid)>x){
            r=mid-1;
            res=mid;
        }
        else{
            l=mid+1;
        }
    }

    cout<<x*(res-1)+(x+1)*(m-res+1)<<'\n';
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