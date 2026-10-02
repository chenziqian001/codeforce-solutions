#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> get(int x){
    vector<int> r;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            r.push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) r.push_back(x);
    return r;
}


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int g=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        g=__gcd(g,a[i]);
    }
    int c=0;
    for(int i=0;i<n;i++){
        a[i]/=g;
        if(a[i]==1) c++;
    }
    if(c>=2){
        cout<<"NO"<<'\n';
        return;
    }
    vector<int> p1;
    for(int i=0;i<min(n,3LL);i++){
        vector<int> v=get(a[i]);
        for(int x:v) p1.push_back(x);
    }
    sort(p1.begin(),p1.end());
    p1.erase(unique(p1.begin(),p1.end()),p1.end());
    for(int p:p1){
        vector<int> u;
        for(int i=0;i<n;i++){
            if(a[i]%p!=0) u.push_back(a[i]);
        }
        if(u.size()<=1){
            cout<<"YES"<<'\n';
            return;
        }
        vector<int> p2;
        for(int i=0;i<min((int)u.size(),2LL);i++){
            vector<int> v=get(u[i]);
            for(int x:v) p2.push_back(x);
        }
        for(int q:p2){
            int c2=0;
            for(int x:u){
                if(x%q!=0){
                    c2++;
                    if(c2>1) break;
                }
            }
            if(c2<=1){
                cout<<"YES"<<'\n';
                return;
            }
        }
    }
    cout<<"NO"<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}