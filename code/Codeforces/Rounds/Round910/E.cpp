#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    string t;
    cin>>s;
    cin>>t;

    vector<vector<int>> pos(26);
    for(int i=n-1;i>=0;i--){
        pos[s[i]-'a'].push_back(i);
    } 


    for(int i=0;i<m;i++){
        int x=t[i]-'a';
        if(pos[x].empty()){
            cout<<"NO"<<'\n';
            return;
        }

        int p=pos[x].back();
        pos[x].pop_back();

        for(int j=0;j<x;j++){
            while(!pos[j].empty() && pos[j].back()<p){
                pos[j].pop_back();
            }
        }
    }

    cout<<"YES"<<'\n';
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