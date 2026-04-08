#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(st.empty() || x>=st.top()){
            st.push(x);
        }
    }

    cout<<st.size()<<'\n';



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}