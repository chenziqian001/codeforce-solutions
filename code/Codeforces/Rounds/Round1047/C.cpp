#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b;
    cin>>a>>b;
    if(b%2==1 && a%2==0){
        cout<<-1<<'\n';
        return;
    }
    else if(b%2==1 && a%2==1){
        cout<<a*b+1LL<<'\n';
    }
    else if(b%2==0 && a%2==0){
        long long re=b/2;
        cout<<a*re+2LL<<'\n';
    }
    else{
        long long re=b/2;
        if(re%2==1){
            cout<<-1<<'\n';
        }
        else{
            cout<<a*re+2<<'\n';
        }
    }


    
}



 

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}