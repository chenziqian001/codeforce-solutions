#include<bits/stdc++.h>
using namespace std;
auto get(vector<int> a){
    int n=a.size();
    vector<array<int,2>> ans;
    set<int> s[3];
    for(int i=0;i<n;i++) s[a[i]].insert(i);

    auto change=[&](int i,int j){
        ans.push_back({i+1,j+1});
        s[a[i]].erase(i);
        s[a[j]].erase(j);
        swap(a[i],a[j]);
        s[a[i]].insert(i);
        s[a[j]].insert(j);
    };

    for(int i=0;i<n;i++){
        if(s[1].empty()){

        }
        else if(s[0].empty()){
            if(a[i]==2) change(i,*s[1].begin());
        }
        else{
            if(a[i]==2) change(i,*s[1].begin());
            if(a[i]==1) change(i,*s[0].begin());
        }
        s[a[i]].erase(i);
    }

    return ans;
}


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    auto ans=get(a);
    if(ans.size()>n){
        reverse(a.begin(),a.end());
        for(auto &x:a){
            x=2-x;
        }
        ans=get(a);
        for(auto &[u,v]:ans){
            u=n+1-u;
            v=n+1-v;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [u,v]:ans){
        cout<<u<<" "<<v<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
