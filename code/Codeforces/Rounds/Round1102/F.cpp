#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int pos=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>a[pos]) pos=i;
    }
    vector<int> b(n-1);
    for(int i=0;i<n-1;i++) b[i]=a[(pos+1+i)%n];
    
    vector<int> L(n),R(n);
    vector<pair<int,int>> s;
    int sum=0;
    
    for(int i=1;i<n;i++){
        int val=b[i-1];
        int c=1;
        while(s.size()&&s.back().first<=val){
            c+=s.back().second;
            sum-=s.back().first*s.back().second;
            s.pop_back();
        }
        s.push_back({val,c});
        sum+=val*c;
        L[i]=sum;
    }
    
    s.clear();
    sum=0;
    
    for(int i=n-2;i>=0;i--){
        int val=b[i];
        int c=1;
        while(s.size()&&s.back().first<=val){
            c+=s.back().second;
            sum-=s.back().first*s.back().second;
            s.pop_back();
        }
        s.push_back({val,c});
        sum+=val*c;
        R[i]=sum;
    }
    
    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[(pos+1+i)%n]=L[i]+R[i];
    
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<"\n";


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