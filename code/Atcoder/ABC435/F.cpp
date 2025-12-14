#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int ls[N],rs[N];
int f[N];

void dfs(int node){
    int mx=0;
    if(ls[node]!=0){
        dfs(ls[node]);
        mx=max(mx,f[ls[node]]+abs(node-ls[node]));
    }

    if(rs[node]!=0){
        dfs(rs[node]);
        mx=max(mx,f[rs[node]]+abs(node-rs[node]));
    }
    f[node]=mx;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    stack<int> st;
    

    for(int i=1;i<=n;i++){
        int pre=0;
        while(!st.empty() && a[st.top()]<a[i]){
            pre=st.top();
            st.pop();
        }
        ls[i]=pre;
        if(!st.empty()){
            rs[st.top()]=i;
        }
        st.push(i);
    }

    int root=0;
    for(int i=1;i<=n;i++){
        if(a[i]==n){
            root=i;
            break;
        }
    }
    dfs(root);
    cout<<f[root]<<'\n';

    //system("pause");


}



