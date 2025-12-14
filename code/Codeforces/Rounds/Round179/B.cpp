#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string a;
    string b;
    cin>>a;
    cin>>b;
    a=' '+a;
    b=' '+b;

    vector<vector<vector<int>>> f(n+1,vector<vector<int>>(2,vector<int>(2)));
    f[0][0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(char c1='0';c1<='9';c1++){
                    if(a[i]=='?' || a[i]==c1){
                        for(char c2='0';c2<='9';c2++){
                            if(b[i]=='?' || b[i]==c2){
                                f[i][j|(c1<c2)][k|(c1>c2)]=(f[i][j|(c1<c2)][k|(c1>c2)]+f[i-1][j][k])%mod;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<f[n][1][1]<<'\n';
    //system("pause");
    return 0;
}