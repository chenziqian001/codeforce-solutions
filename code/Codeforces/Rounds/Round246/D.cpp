#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i]){
            l=i,r=i+z[i];
            z[i]++;
        }
    }
    vector<int> f(n+1);
    for(int x:z) f[x]++;
    for(int i=n;i>=1;i--) f[i-1]+=f[i];
    vector<int> res;
    for(int i=n-1;i>=0;i--){
        if(i+z[i]==n){
            res.push_back(z[i]);
        }
    }
    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x<<" "<<f[x]<<'\n';
    }
}
