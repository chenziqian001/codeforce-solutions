#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    x--,y--;
    vector<int> res(n); 
    for(int i=0;i<n;i++) res[(x+i)%n]=i%2;
    if(n%2 || (x-y)%2==0){
        res[x]=2;
    } 
    for(int x:res){
        cout<<x<<" ";
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


