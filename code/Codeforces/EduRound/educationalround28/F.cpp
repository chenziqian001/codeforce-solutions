#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> last(1000007,-1);
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=1LL*(i-last[a[i]])*(n-i);
    }
    double res = double(ans * 2 - n) / (1.0 * n * n);
    cout<<res<<'\n';
}