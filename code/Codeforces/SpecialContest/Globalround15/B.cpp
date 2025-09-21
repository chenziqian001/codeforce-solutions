#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> scores(n,vector<int>(5));
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>scores[i][j];
        }
    }
    vector<int> wa={scores[0][0],scores[0][1],scores[0][2],scores[0][3],scores[0][4]};
    int w=0;
    for(int i=1;i<n;i++){
        int cnt=0;
        for(int j=0;j<5;j++){
            if(scores[i][j]<wa[j]) cnt++; 
        }
        if(cnt>=3){
            w=i;
            for(int j=0;j<5;j++){
                wa[j]=scores[i][j];
            }
        }
    }
    bool ok=true;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<5;j++){
            if(scores[i][j]<wa[j]) cnt++; 
        }
        if(cnt>=3){
            ok=false;
            break;
        }
    }
    if(!ok) cout<<-1<<'\n';
    else cout<<w+1<<'\n';
    



}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}