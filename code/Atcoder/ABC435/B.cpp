#include<bits/stdc++.h>
using namespace std;





int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];


    vector<int> s(n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    int res=0;
    for(int l=1;l<=n;l++){
        for(int r=l+1;r<=n;r++){
            int val=s[r]-s[l-1];
            bool ok=true;
            for(int i=l;i<=r;i++){
                if(val%a[i]==0){
                    ok=false;
                    break;
                }
            }
            if(ok) res++;
        }
    }
    cout<<res<<'\n';


    //system("pause");
}