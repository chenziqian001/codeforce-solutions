#include<bits/stdc++.h>
using namespace std;


int get(char a,char b,char c){
    return ((a=='A')+(b=='A')+(c=='A'))>=2;
}

void solve(){
    int n;
    cin>>n;
    vector<string> s(2);
    cin>>s[0];cin>>s[1];
    

    vector<int> f(n+1),g(n+1),h(n+1);


    for(int i=0;i<n;i++){
        if(i%3==0){
            f[i+3]=max(f[i+3],f[i]+get(s[0][i],s[0][i+1],s[0][i+2])+get(s[1][i],s[1][i+1],s[1][i+2]));
            g[i+1]=max(g[i+1],f[i]+get(s[0][i],s[0][i+1],s[1][i]));
            h[i+1]=max(h[i+1],f[i]+get(s[1][i],s[1][i+1],s[0][i]));
        }
        if(i%3==1){
            if(i+3<n){
                g[i+3]=max(g[i+3],g[i]+get(s[0][i+1],s[0][i+2],s[0][i+3])+get(s[1][i],s[1][i+1],s[1][i+2]));
                h[i+3]=max(h[i+3],h[i]+get(s[0][i],s[0][i+1],s[0][i+2])+get(s[1][i+1],s[1][i+2],s[1][i+3]));
            }
            f[i+2]=max(f[i + 2], g[i] + get(s[0][i + 1], s[1][i], s[1][i + 1]));
            f[i+2]=max(f[i + 2], h[i] + get(s[1][i + 1], s[0][i], s[0][i + 1]));
        }
    }
    cout<<f[n]<<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}