#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;


struct trie{
    int son[2];
}t[N*30];
int idx;



void insert(int val){
    int p=0;
    for(int i=30;i>=0;i--){
        int st=val>>i&1;
        if(!t[p].son[st]) t[p].son[st]=++idx;
        p=t[p].son[st];
    }
}


int dp(int node){
    int ls=t[node].son[0];
    int rs=t[node].son[1];

    if(!ls && !rs) return 1;
    if(!ls) return dp(rs);
    if(!rs) return dp(ls);
    return max(dp(ls),dp(rs))+1;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    idx=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(x);
    }

    cout<<n-dp(0)<<'\n';
    //system("pause");

}