#include<bits/stdc++.h>
using namespace std;
int get(string a,string b){
    string nb=b;
    int n=a.size();
    for(int i=0;i<n-2;i++){
        if(a[i]=='0' && a[i]==a[i+2]){
            nb[i+1]='1';
        }
    }
    string na=a;
    for(int i=0;i<n-2;i++){
        if(nb[i]=='1' && nb[i]==nb[i+2]){
            na[i+1]='1';
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(na[i]=='1');
    }
    return cnt;
}
void solve(){
    int n;
    cin>>n;
    string s;
    string t;
    cin>>s;
    cin>>t;
    string nt=t;
    for(int i=0;i<n-2;i++){
        if(s[i]=='0' && s[i]==s[i+2]){
            nt[i+1]='1';
        }
    }
    string ns=s;
    for(int i=0;i<n-2;i++){
        if(nt[i]=='1' && nt[i]==nt[i+2]){
            ns[i+1]='1';
        }
    }
    vector<int> pre(n+1);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+(ns[i]=='1');
    }
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(r-l+1<=5){
            cout<<get(s.substr(l,r-l+1),t.substr(l,r-l+1))<<'\n';
        }
        else{
            int res=pre[r-1]-pre[l+2];
            res+=(s[l]=='1')+(s[r]=='1');
            res+=(s[l+1]=='1' || (t[l]=='1'&&nt[l+2]=='1'));
            res+=(s[r-1]=='1' || (t[r]=='1' && nt[r-2]=='1'));
            cout<<res<<'\n';
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0; 
}