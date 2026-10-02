#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,x;
    cin>>a>>b>>x;

    vector<int> A,B;
    for(int v=a;v>0;v/=x) A.push_back(v); 
    A.push_back(0);
    for(int v=b;v>0;v/=x) B.push_back(v); 
    B.push_back(0);
    
    int res=2e18;
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
            res=min(res,i+j+abs(A[i]-B[j]));
            
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