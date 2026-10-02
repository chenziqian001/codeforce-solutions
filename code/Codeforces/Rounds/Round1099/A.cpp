#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    set<int> st;
    vector<int> res;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if(res.empty()){
                res.push_back(j);
                st.insert(j);
                break;
            } 
            if(st.count(j) || st.count(j+res.back())) continue;
            st.insert(j+res.back());
            res.push_back(j);
            st.insert(j);
            
            break;
        }
    }
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<'\n';


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