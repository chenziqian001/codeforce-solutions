#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int id,pos,l,r;    
};

void solve(){
    int n;
    cin>>n;
    stack<node> st;
    vector<int> L(n),R(n);
    for(int i=0;i<n;i++) cin>>L[i]>>R[i];
    string res="";
    for(int i=0;i<n;i++){
        res+='(';
        st.push({i,(int)res.size()-1,L[i],R[i]});
        while(!st.empty()){
            int dis=res.size()-st.top().pos;
            if(dis>=st.top().l && dis<=st.top().r){
                st.pop();
                res+=')';
            }
            else if(dis>st.top().r){
                cout<<"IMPOSSIBLE"<<'\n';
                return;
            }
            else break;
        }
    }
    if(st.empty()){
        cout<<res<<'\n';
    }
    else {
        cout<<"IMPOSSIBLE"<<'\n';
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}