#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        int base=1;
        while(true){
            int c=(n+1)/2;
            if(k<=c){
                cout<<(2*k-1)*base<<'\n';
                break;
            }
            k-=c;
            n/=2;
            base*=2;
        }
    }

    //system("pause");
    return 0;
}