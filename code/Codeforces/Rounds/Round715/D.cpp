#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s[3];
    cin>>s[0]>>s[1]>>s[2];

    for(int c=0;c<2;c++){
        char ch=c+'0';
        vector<int> v;
        for(int i=0;i<3;i++){
            int cnt=0;
            for(char x:s[i]) if(x==ch) cnt++;
            if(cnt>=n) v.push_back(i);
        }
        
        if(v.size()>=2){
            string a=s[v[0]],b=s[v[1]],ans="";
            int i=0,j=0;
            while(i<2*n&&j<2*n){
                if(a[i]==b[j]){
                    ans+=a[i];
                    i++;j++;
                }else if(a[i]!=ch){
                    ans+=a[i];
                    i++;
                }else{
                    ans+=b[j];
                    j++;
                }
            }
            while(i<2*n) ans+=a[i++];
            while(j<2*n) ans+=b[j++];
            cout<<ans<<'\n';
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}