#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        if(r-l+1>=50){
            cout<<"YES"<<'\n';
        }
        else{
            vector<int> tmp;
            for(int i=l;i<=r;i++){
                tmp.push_back(a[i]);
            }
            sort(tmp.begin(),tmp.end());
            int m=tmp.size();
            bool ok=false;
            for(int i=0;i<m;i++){
                for(int j=i+1;j<m;j++){
                    for(int k=j+1;k<m;k++){
                        if(tmp[k]<tmp[i]+tmp[j]){
                            vector<int> b;
                            for (int p=0; p<m; p++) if (p!=i && p!=j && p!=k) b.push_back(tmp[p]);
    
                            for (int p=0; p<(int)b.size()-2; p++) {
                                if (b[p] + b[p+1] > b[p+2]){
                                    ok=true;
                                    break;
                                }
                            }
                            if(ok) break;
                        }                    
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
            if(ok){
                cout<<"YES"<<'\n';
            }
            else cout<<"NO"<<'\n';
        }
    }






}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;

}


