#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ml=1;
    long long mini=1e13+10;
    for(int i=0;i<n;i++){
        if(i==0) mini=min(mini,(long long)a[i]*(n-1));
        else{
            if(a[i]==a[i-1]){
                ml++;
                mini=min(mini,(long long)(n-ml)*a[i]);
            }
            else{
                ml=1;
                mini=min(mini,(long long)(n-1)*a[i]);
            }
        } 
    }

    cout<<mini<<'\n';
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}