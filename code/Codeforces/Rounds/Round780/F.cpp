#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c[2];
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[j]=='-') c[0]++;
            else c[1]++;
            int d=c[0]-c[1];
            if(d<0) continue;
            if(d%3==0){
                res++;
            }
        }
        c[0]=0;
        c[1]=0;
    }
    cout<<res<<'\n';
}
*/

void solve(){
    int n;
    cin>>n;
    int m=2*n+1;
    string s;
    cin>>s;
    int res=0;
    auto add=[&](int pos,int val,vector<int> &fw){
        for(int i=pos;i<=m;i+=i&-i) fw[i]+=val;
    };
    auto get=[&](int pos,vector<int> &fw){
        int res=0;
        for(int i=pos;i>0;i-=i&-i){
            res+=fw[i];
        }
        return res;
    };
    for(int i=0;i<3;i++){
        vector<int> fw(m+1);
        int d=0;
        int b=n+1;
        if(i==0) add(n,1,fw);
        for(int j=0;j<n;j++){
            if(s[j]=='-'){
                d++;
                b++; 
            }
            else{
                d+=2;
                b--;
            }
            if(d%3==i){
                res+=get(b,fw);
                add(b,1,fw);
            }
        }
    }
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