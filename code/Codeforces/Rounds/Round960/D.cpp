#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int op1=0,op2=0;
    int res=0;
    for(int i=0;i<n;i++){
        if((!op1)&&(!op2)){
            if(a[i]==0) continue;
            res++;
            if(a[i]<=2) op1=1;
        }
        else if(op1){
            op1=0;
            if(a[i]<=2) continue;
            res++;
            if(a[i]<=4) op2=1; 
        }
        else{
            op2=0;
            if(a[i]==0) continue;
            res++;
            if(a[i]<=4) op1=1;
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