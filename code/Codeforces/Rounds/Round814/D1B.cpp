#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> fib;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int pre=0;
    int pos=-1;
    for(int i=0;i<fib.size();i++){
        pre+=fib[i];
        if(pre==sum){
            pos=i;
            break;
        }
    } 
    if(pos==-1){
        cout<<"NO"<<'\n';
        return;
    }
    int pev=-1;
    for(int i=pos;i>=0;i--){
        int mx=*max_element(a.begin(),a.end());
        if(mx<fib[i]){
            cout<<"NO"<<'\n';
            return;
        }
        bool ok=false;
        for(int j=0;j<n;j++){
            if(a[j]==mx && j!=pev){
                a[j]-=fib[i];
                pev=j;
                ok=true;
                break;
            }
        }
        if(!ok){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fib={1,1};
    int p=1;
    while(fib.back()<1e12){
        int np=fib.back();
        fib.push_back(p+fib.back());
        p=np;
    }
    
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
