#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> h(n),v(m),u;

    int h1=0;
    for(int i=0;i<n;i++){
        cin>>h[i];
        h1+=h[i]==1;
    }
    for(int i=0;i<m;i++){
        cin>>v[i];
    }

    int a=n-max(0LL,h1-1);
    bool ok=false;
    for(int i=0;i<n;i++){
        if(h[i]>=2){
            u.push_back(h[i]-1);
        }
        else{
            if(!ok){
                u.push_back(0);
                ok=true;
            }
            else u.push_back(1);
        }
    }
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());

    int i=0,j=0;
    int at=0;

    int aoe=0;
    while(j<m){
        if(i<n && u[i]<=aoe){
            aoe++;
            i++;
        }
        else if(v[j]<=aoe){
            aoe++;
            j++;
        }
        else{
            at+=v[j]-aoe;
            j++;
            aoe++;
        }
    }

    if(at<=a){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }

}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

