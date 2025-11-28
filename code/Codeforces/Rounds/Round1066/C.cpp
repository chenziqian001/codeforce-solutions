#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,k,q;
    cin>>n>>k>>q;

    vector<int> res(n);
    vector<int> mn(n);
    vector<int> mex(n);
    
    for(int i=0;i<q;i++){
        int c,l,r;
        cin>>c>>l>>r;
        l--,r--;
        if(c==1){
            for(int j=l;j<=r;j++){
                mn[j]=1;
            }   
        }
        else{
            for(int j=l;j<=r;j++){
                mex[j]=1;
            }   

        }
    }

    for(int i=0;i<n;i++){
        if(mn[i] && mex[i]) res[i]=k+1;
        else if(mn[i]) res[i]=k;
        else res[i]=i%k;
    }

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
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


