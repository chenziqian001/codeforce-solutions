#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    auto check=[&](vector<int> &a){
        int res;
        cout<<'?'<<" ";
        cout<<a.size()<<" ";
        for(int x:a){
            cout<<x<<" ";
        }
        cout<<endl;
        cin>>res;
        return (a.size()-res)%2;
    };
    int l=3,r=2*n+1;
    int p3=r;
    while(l<=r){
        int mid=(l+r)/2;
        vector<int> tmp;
        for(int i=1;i<=mid;i++) tmp.push_back(i);
        int res=check(tmp);
        if(res){
            p3=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    l=1;r=p3-2;
    int p1=1;
    while(l<=r){
        int mid=(l+r)/2;
        vector<int> tmp;
        for(int i=mid;i<=2*n+1;i++) tmp.push_back(i);
        if(check(tmp)){
            p1=mid;
            l=mid+1;
        }else r=mid-1;
    }
    l=p1+1,r=p3-1;
    int p2=r;
    while(l<=r){
        int mid=(l+r)/2;
        vector<int> tmp={p1,p3};
        for(int i=p1+1;i<=mid;i++) tmp.push_back(i);
        int res=check(tmp);
        if(res){
            p2=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<'!'<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
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