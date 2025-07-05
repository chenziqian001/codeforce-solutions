#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    string s(n);
    cin>>s;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int pos=-1;
    
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            a[i]=-1e13;
            pos=i;
        }
    }
    long long mx=0;
    long long cur=0;
    for(int i=0;i<n;i++){
        cur=max(cur+a[i],a[i]);
        mx=max(mx,cur);
    }
    if(mx>k||(mx!=k&&pos==-1)){

        cout<<"No"<<'\n';
        return;
    }


    if(pos!=-1){
        mx=0;
        cur=0;
        long long L,R;
        for(int i=pos+1;i<n;i++){
            cur+=a[i];
            mx=max(mx,cur);
        }
        R=mx;
        mx=0;
        cur=0;
        for(int j=pos-1;j>=0;j--){
            cur+=a[j];
            mx=max(cur,mx);
        }
        L=mx;
        a[pos]=k-L-R;
    }
    cout<<"Yes"<<'\n';

   for(int i=0; i<n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}