#include<iostream>
#include<vector>

using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        if(k>0){
            cout<<"1";
            k--;
        }
        else{
            cout<<"0";
        }
        
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