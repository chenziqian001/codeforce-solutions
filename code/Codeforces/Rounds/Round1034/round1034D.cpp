#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(s[i]=='1');
    }
    if(k>=cnt){
        cout<<"Alice"<<'\n';
    }
    else{
        int half=n/2;
        if(k-1>=half) cout<<"Alice"<<'\n';
        else cout<<"Bob"<<'\n';        
    }

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
