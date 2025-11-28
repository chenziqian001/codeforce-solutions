#include<bits/stdc++.h>
using namespace std;



void solve(){

    int n,k;
    cin>>n>>k;
 
    bool ok=true;
    int pos=-1;
    
    vector<int> a(n);
    vector<int> ap(n+1);
    for(int i=0;i<n;i++) cin>>a[i],ap[a[i]]++;
    
    for(int i=1;i<=n;i++){
        if(!ap[i]){
            pos=i;
            ok=false;
            break;
        }
    }
    
    int b[3];
    if(ok){
        b[0]=a[0],b[1]=a[1],b[2]=a[2];
    }
    else{
        b[0]=pos;
        b[2]=a[n-1];
        for(int i=1;i<=n;i++){
            if(i!=b[0] && i!=b[2]){
                b[1]=i;
                break;
            }
        }
    }


    for(int i=0;i<k;i++){
        cout<<b[i%3]<<" ";
    }
    cout<<'\n';

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}


