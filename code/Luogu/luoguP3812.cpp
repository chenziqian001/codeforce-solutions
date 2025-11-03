#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> basis(51);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int x:a){
        for(int i=50;i>=0;i--){
            if((x>>i)&1){
                if(!basis[i]){
                    basis[i]=x;
                    break;
                }
                x^=basis[i];  
            }
        }    
    }
    int res=0;
    for(int i=50;i>=0;i--){
        if((res^basis[i])>res){
            res=res^basis[i];
        }
    }

    cout<<res<<'\n';
    //system("pause");
}