#include<iostream>
#include<vector>

using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%3==0){
        if((a+b+c)/3<b){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
        return;
    }
    cout<<"NO"<<'\n';
    

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();

    system("pause");
    return 0;
}