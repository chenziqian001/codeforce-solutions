#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        int n,a=1;
        cin>>n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                int c=0;
                while(n%i==0){
                    c++;
                    n/=i;
                }
                a*=2*c+1;
            }
        }
        if(n>1) a*=3;
        cout<<(a+1)/2<<"\n";
    }
    //system("pause");
    return 0;
}