#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;


    int x=0,y=0,z=0;
    vector<int> cnt(m);
    set<int> st;
    for(int i=0;i<n;i++){
        vector<int> a(m);
        for(int j=0;j<m;j++){
            cin>>a[j];
            if(a[j]>0){
                cnt[j]+=a[j];
                st.insert(j);
                x+=a[j];
            }
        }


        for(int j=0;j<m;j++){
            if(a[j]>0) continue;
            int d=-a[j];
            y+=d;
            while(d>0){
                auto it = st.upper_bound(j);
                if(it==st.begin()) break;
                --it;
                int k=*it;
                int tk=min(d,cnt[k]);
                cnt[k]-=tk;
                d-=tk;
                z+=tk;
                if(cnt[k]==0) st.erase(k);
            }
            
        }
    }

    cout<<x+y-2*z<<'\n';
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