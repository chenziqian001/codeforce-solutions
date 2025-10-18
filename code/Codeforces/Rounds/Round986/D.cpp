#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> p(3,vector<int>(n));
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++) cin>>p[i][j];
    }
    string s="qkj";
    vector<int> mins={n-1,n-1,n-1};
    vector<pair<char,int>> path(n,{'\0',-1});
    for(int i=n-2;i>=0;i--){
        int who=-1;
        for(int j=0;j<3;j++){
            if(p[j][i]>p[j][mins[j]]){
                who=j;
            }
        }
        if(i==0 && who==-1){
            cout<<"NO"<<'\n';
            return;
        }    
        if(who==-1) continue;
        path[i]={s[who],mins[who]+1};
        for(int j=0;j<3;j++){
            if(p[j][i]<p[j][mins[j]]){
                mins[j]=i;
            }
        }
    }
    cout<<"YES"<<'\n';
  
    vector<pair<char,int>> ans={path[0]};
    while(ans.back().second>=0){
        ans.push_back(path[ans.back().second-1]);
    }
    ans.pop_back();
    cout<<(int)ans.size()<<'\n';
    for(auto pr:ans){
        cout<<pr.first<<" "<<pr.second<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}