#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int res=0;
    string t="nanjing";
    for(int i=0;i<n;i++){
        if(s[i]=='n'){
            if((i+7-1)<n && s.substr(i,7)==t){
                res++;
            }
            else if((i+7-1)>=n && s.substr(i,n-i)==t.substr(0,n-i)){
                if(s.substr(0,7-n+i)==t.substr(n-i,7-n+i) && k>=(7-n+i)){
                    k-=(7-n+i);
                    res++;
                }
            }
        }
    }
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;   
}