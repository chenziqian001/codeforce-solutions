#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
vector<bool> isp;
void init(){
    isp.assign(N,true);
    isp[0]=isp[1]=false;
    for(int i=2;i<N;i++){
        if(isp[i]){
            for(int j=i*2;j<N;j+=i){
                isp[j]=false;
            }
        }
    }
};


vector<int> get(int n,int val){
    vector<int> res;
    res.push_back(val);
    for(int i=1;i<=n;i++){
        if(val-i>0) res.push_back(val-i);
        if(val+i<=n) res.push_back(val+i);
    }
    return res;
}



void solve(){
    int n;
    cin>>n;
    vector<int> res;

    for(int x=0;;x++){
        if((n/2-x)>=1 &&  isp[n/2-x]){
            res=get(n,n/2-x);
            break;
        }
        if((n/2-x)<=n && isp[n/2+x]){
            res=get(n,n/2+x);
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';

}



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}



