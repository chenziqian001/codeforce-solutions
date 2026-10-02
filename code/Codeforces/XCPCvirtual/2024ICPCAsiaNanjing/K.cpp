#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k,w;
    cin>>n>>m>>k>>w;
    vector<pair<int,int>> a(m+n+2);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,1};
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        a[i+n]={x,0};
    }
    a[n+m]={w+1,0};
    sort(a.begin(),a.end());
    bool ok=true;
    int L=0,R=0;
    vector<int> res;
    for(int i=0;i<a.size();i++){
        if(a[i].second) continue;
        L=R,R=i;
        vector<int> ans;
        for(int j=L+1;j<R;j++){
            int tmp=a[j].first;
            ans.push_back(tmp);
            while(j+1<R && a[j+1].first<tmp+k) j++;
        }
        if(ans.empty()) continue;
        ans.push_back(a[R].first);
        for(int j=ans.size()-1;j;j--){
            if(ans[j-1]>ans[j]-k){
                ans[j-1]=ans[j]-k;
            }
        }
        if(ans[0]<=a[L].first){
            ok=false;
            break;
        }
        ans.pop_back();;
        for(auto x:ans){
            res.push_back(x);
        }
    }
    if(!ok){
        cout<<-1<<'\n';
    }
    else{
        cout<<res.size()<<'\n';
        for(auto x:res){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}