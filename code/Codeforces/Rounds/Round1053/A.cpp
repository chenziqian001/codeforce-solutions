#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    set<int> black;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        black.insert(x);
    }
    int pos=1;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            pos+=1;
            black.insert(pos);
        }
        else{
            pos+=1;
            while(black.count(pos)) pos++;
            black.insert(pos);
            while(black.count(pos)) pos++;
            
        }
    }

    cout<<black.size()<<'\n';
    for(int x:black){
        cout<<x<<" ";
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