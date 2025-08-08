#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int cur=0;
    int i=0;
    int res=0;
    while(i<n){
        if(a[i]==0){
            cur++;
            if(cur==k){
                res++;
                i+=2;
                cur=0;
            }
            else i++;
        }
        else{
            i++;
            cur=0;
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