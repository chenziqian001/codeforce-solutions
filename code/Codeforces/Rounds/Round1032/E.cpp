#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int n;
const int inf=1e9;

int dfs(int i,int ovl,bool bga,bool smb){
    
    int res=inf;
    if(i==n) return res=min(res,ovl);
    if(bga && smb){
        res=min(res,ovl);
    }
    else if(bga){
        for(char c=b[i];c>='0';c--){
            res=min(res,dfs(i+1,ovl+(c==a[i])+(c==b[i]),true,c!=b[i]));
        }
    }
    else if(smb){
        for(char c=a[i];c<='9';c++){
            res=min(res,dfs(i+1,ovl+(c==a[i])+(c==b[i]),c!=a[i],true));
        }
    }
    else {
        if(a[i]==b[i]){
            res=min(res,dfs(i+1,ovl+2,false,false));
        }
        if(a[i]-'0'+1==b[i]-'0'){
            res=min(res,dfs(i+1,ovl+1,false,true));//和a保持一致
            res=min(res,dfs(i+1,ovl+1,true,false));//和b保持一致
        }
        if((a[i]-'0'+1)<(b[i]-'0')) res=min(res,ovl);
    }
    return res;
}


void solve(){
    int l,r;
    cin>>l>>r;
    a=to_string(l);
    b=to_string(r);
    n=a.size();
    cout<<dfs(0,0,false,false)<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }   
    return 0;
}