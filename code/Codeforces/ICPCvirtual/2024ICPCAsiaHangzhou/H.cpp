#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> chains(k);
    int cnt=0;
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        chains[cnt++]={l,r};
    }
    sort(chains.begin(),chains.end(),[&](vector<int> a,vector<int> b){
        return (a[1]-a[0])>(b[1]-b[0]);
    });
    int mx_len=chains[0][1]-chains[0][0];
    bool case1=false;
    if(k>1){
        if(mx_len==(chains[1][1]-chains[1][0])){
            case1=true;
            int min_len=chains[k-1][1]-chains[k-1][0];
            if(min_len+1>=mx_len){
                cout<<"IMPOSSIBLE"<<'\n';
                return;
            }  
        }
    }
    vector<int> pa(n+1);
    int rt=chains[0][0];
    int ed=chains[0][1];
    pa[rt]=0;
    for(int i=rt+1;i<=ed;i++){
        pa[i]=i-1;
    }
    for(int i=1;i<k;i++){
        int l=chains[i][0],r=chains[i][1];
        if(i==k-1 && case1){
            pa[l]=rt+1;
        }
        else pa[l]=rt;
        for(int j=l+1;j<=r;j++){
            pa[j]=j-1;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<pa[i]<<" ";
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}