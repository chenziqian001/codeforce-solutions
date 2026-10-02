#include<bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int cnto[26]={0},cnte[26]={0};
    for(int i=0;i<n;i++){
        if(i%2==0) cnto[s[i]-'a']++;
        else cnte[s[i]-'a']++;
    }
    if(n%2){
        bool ok=true;
        int pos=n/2;
        for(int i=0;i<26;i++){
            if(cnto[i]%2==1){
                if(pos%2 || ok==false){
                    cout<<"NO"<<'\n';
                    return;
                }
                else if(pos%2==0 && ok==true) ok=false;
            }
            if(cnte[i]%2==1){
                if(pos%2==0 || ok==false){
                    cout<<"NO"<<'\n';
                    return;
                }
                else if(pos%2 && ok==true) ok=false;
            }
        }
        cout<<"YES"<<'\n';
        return;
    }
    for(int i=0;i<26;i++){
        if(cnto[i]!=cnte[i]){
            cout<<"NO"<<'\n';
            return;
        }
    }

    cout<<"YES"<<'\n';
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


