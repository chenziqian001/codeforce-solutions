#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=-1e18;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    vector<int> c=a;
    c.insert(c.end(),b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int va=2*n;
    int vb=2*m;
    int res=va-vb;
    for(int i=0;i<c.size();i++){
        int base=c[i];

        auto it1=lower_bound(a.begin(),a.end(),base);
        int sca=(it1==a.end()?0:n-(it1-a.begin()))+2*n;

        auto it2=lower_bound(b.begin(),b.end(),base);
        int scb=(it2==b.end()?0:m-(it2-b.begin()))+2*m;
        
        if(sca-scb>res || ((sca-scb==res)&&(sca>va))){
            res=sca-scb;
            va=sca;
            vb=scb;
        }
    }
    cout<<va<<":"<<vb<<'\n';
    //system("pause");
}