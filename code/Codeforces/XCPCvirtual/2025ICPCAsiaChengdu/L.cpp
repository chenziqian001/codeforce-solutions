#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<100<<'\n';
    for(int i=0;i<100;i++){
        if(i<50){
            cout<<a<<" ";
        }
        else if(i<95) cout<<b<<" ";
        else if(i<99) cout<<c<<" ";
        else cout<<c+1;
    }
    cout<<'\n';
    return 0;
}