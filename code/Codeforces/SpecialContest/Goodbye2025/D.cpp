#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    if(m>n/2){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>> ans;
    auto print=[&](){
        cout<<ans.size()<<endl;
        for(auto p:ans){
            cout<<p.first<<" "<<p.second<<endl;
        }
    };
    sort(a.begin(),a.end(),[&](pair<int,int> x,pair<int,int> y){
        return x.first>y.first;
    });


    if(m==0){
        int x=a[0].first;
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=a[i].first;
            if(sum>=x){
                for(int j=i+1;j<n;j++){
                    ans.push_back({a[j].second,a[j-1].second});
                }
                reverse(ans.begin(),ans.end());
                for(int j=i;j>=1;j--){
                    ans.push_back({a[j].second,a[0].second});
                }
                print();
                return;
            }

        }
        cout<<-1<<'\n';
        return;
    }
    else{
        for(int i=0;i<m;i++){
            ans.push_back({a[i].second,a[i+m].second});
        }
        for(int i=2*m-1;i<n-1;i++){
            ans.push_back({a[i].second,a[i+1].second});
        }
        reverse(ans.begin(),ans.end());
    }
    print();
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