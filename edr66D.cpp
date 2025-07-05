#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n]{};
    for(int i=0;i<n;i++) cin>>a[i];
    long long prefix[n+1]{};
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i-1];
    }
    k--;
    vector<long long> back_fix;
    for(int i=1;i<n;i++){
        back_fix.push_back(prefix[n]-prefix[i]);
    }
    long long res=0;
    sort(back_fix.begin(),back_fix.end(),[](long long a,long long b){
        return a>b;
    });
    for(int i=0;i<k;i++){
        res+=back_fix[i];
    }
    cout<<res+prefix[n]<<'\n';
    system("pause");
    return 0;
}