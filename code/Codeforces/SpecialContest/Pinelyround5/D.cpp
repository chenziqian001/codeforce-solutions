#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        a[i]=x;
        pos[x].push_back(i);
    } 

    int res=0;
    for(int i=0;i<n;i++){
        for(int j=pos[i].size()-1;j>=0;j--){
            if(!pos[i+1].empty() && pos[i+1].back()>pos[i][j]){
                pos[i+1].pop_back();
                res++;
            }
        }
    }


    cout<<res<<'\n';

}


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}


