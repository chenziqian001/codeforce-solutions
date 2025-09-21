#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool cur=(s[0]=='1');
    int cnt=0;
    bool ok=true;
    for(int i=0;i<n;i++){
        if(i==0) continue;
        if(s[i]=='0'){
            cnt++;
        }
        if(s[i]==s[i-1] && s[i]=='0'){
            cur=false;
        }
        if(s[i]==s[i-1] && s[i]=='1'){
            if(cur && cnt%2==1){
                ok=false;
            }
            cur=true;
            cnt=0;
        }
    }


    if(s[n-1]=='1' && cur && cnt%2==1){
        ok=false;
    }
    if(ok) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}


s