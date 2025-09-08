#include<bits/stdc++.h>
using namespace  std;




void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> sum(n+1);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            sum[i]+=__gcd(abs(i-j),n);
        }
        cout<<sum[i]<<" ";
    }
   
    

}


int main(){
    solve();
    system("pause");
    return 0;

    
}