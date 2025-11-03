#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
void solve(){
    int n;
    cin>>n;
    stack<pair<int,int>> st;
    int ans=0;
    for(int i=0;i<n;i++){
        int num,id;
        cin>>num>>id;
        int len=0;
        while(!st.empty() &&(num>0 || id==st.top().second)){
            if(id==st.top().second){
                len+=st.top().first;
                st.pop();
            }
            else{
                int cut=min(st.top().first,num);
                num-=cut;
                len+=cut;
                st.top().first-=cut;
                if(st.top().first==0) st.pop();
            }
        }
        ans+=num;
        len+=num;
        st.emplace(len,id);
        cout<<ans<<" ";
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