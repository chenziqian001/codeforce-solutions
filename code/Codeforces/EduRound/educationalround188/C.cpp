#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int a,b,c,m;
    cin>>a>>b>>c>>m;

    int ab=a*b/__gcd(a,b);
    int ac=a*c/__gcd(a,c);
    int bc=b*c/__gcd(b,c);
    int abc=ab*c/__gcd(ab,c);
    ab=m/ab;
    ac=m/ac;
    bc=m/bc;
    abc=m/abc;

    ab-=abc;
    bc-=abc;
    ac-=abc;


    int cnta=m/a;
    int cntb=m/b;
    int cntc=m/c;

    int resa=0,resb=0,resc=0;
    resa+=abc*2;
    resa+=(cnta-ac-ab-abc)*6;
    resa+=(ac+ab)*3;

    resb+=abc*2;
    resb+=(cntb-bc-ab-abc)*6;
    resb+=(bc+ab)*3;

    resc+=abc*2;
    resc+=(cntc-bc-ac-abc)*6;
    resc+=(bc+ac)*3;

    
    cout<<resa<<" "<<resb<<" "<<resc<<'\n';

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