#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    map<int,int> row,line;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        row[x]++;
        line[x+y]++;
    }
    int r;
    for(auto [x,cnt]:row){
        if(cnt%2==1){
            r=x;
            break;
        }
    }
    int c;
    for(auto [add,cnt]:line){
        if(cnt%2==1){
            c=add-r;
            break;
        }
    }

    cout<<r<<" "<<c<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}