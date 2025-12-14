#include<bits/stdc++.h>
using namespace std;





int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int far=1+a[1]-1;
    int res=1;
    for(int i=2;i<=n;i++){
        if(i<=far){
            res++;
            far=max(far,i+a[i]-1);
        }
        else{
            break;
        }
    }

    cout<<res<<'\n';
    //system("pause");
}