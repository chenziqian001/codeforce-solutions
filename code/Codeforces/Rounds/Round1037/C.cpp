
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n,k;
    cin>>n>>k;
    k--;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int st=a[k];
    set<int> b;
    for(int aa:a){
        b.insert(aa);
    }
    vector<int> c;
    for(int bb:b){
        c.push_back(bb);
    }
    int m=c.size();
    int pos=lower_bound(c.begin(),c.end(),st)-c.begin();
    if(pos==m-1){
        cout<<"YES"<<'\n';
        return;
    }
    int wt=1;
    for(int i=pos;i<m-1;i++){
        if((c[i]-wt)<(c[i+1]-c[i]-1)){
            cout<<"NO"<<'\n';
            return;
        }
        wt+=c[i+1]-c[i];
    }
    cout<<"YES"<<'\n';
 
    
 
}
 
 
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}