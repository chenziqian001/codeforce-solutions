#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    if(n==1){
        if(a[0]==0){
            cout<<1<<'\n';
        }
        else{
            cout<<a[0]<<'\n';
        }
        return;
    }
    int num0=0;
    int num1=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            num1++;
        }
        else if(a[i]==0){
            num0++;
        }
        else{
            res+=a[i];
        }
    }
    res+=min(num0,num1)*2;
    res+=max(num0,num1)-min(num0,num1);
    cout<<res<<'\n';
    
    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}