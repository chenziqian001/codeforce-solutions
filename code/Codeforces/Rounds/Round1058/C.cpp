#include<bits/stdc++.h>
using namespace std;
vector<int> tob(long long n) {
    vector<int> bits;
    if (n == 0) bits.push_back(0); 
    while (n > 0) {
        bits.push_back(n & 1);
        n >>= 1;
    }
    return bits;
}

void solve(){
    long long n;
    cin>>n;
    vector<int> b=tob(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(b[i]==0) cnt++;
        else break;
    }
    for(int i=0;i<cnt;i++) b.push_back(0);
    int len=b.size();
    if(len%2==1){
        if(b[len/2]!=0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    int l=0,r=len-1;
    while(l<=r){
        if(b[l]!=b[r]){
            cout<<"NO"<<'\n';
            return;
        }
        l++;
        r--;
    }
    cout<<"YES"<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}





