#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int cnt=0;
    if(k%2==1){
        if(n%2==1){
            n-=k;
            k--;
            cnt++;
            cnt+=(n+k-1)/k;
        }
        else{
            k--;
            cnt+=(n+k-1)/k;
        }
    }
    else{
        if(n%2==1){
            n-=(k-1);
            cnt+=(n+k-1)/k;
        }
        else{
            cnt+=(n+k-1)/k;
        }
    }
    cout<<cnt<<'\n';
    
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}