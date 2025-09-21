#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    set<int> st; 
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    int m=b.size();
    vector<vector<int>> pos(m);
    for(int i=0;i<n;i++){
        int idx=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        pos[idx].push_back(i);
    }
    map<pair<long long,long long>,long long> mp;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(!st.count(x) || !st.count(y)){
            cout<<0<<'\n';
            continue;
        }
        int idx=lower_bound(b.begin(),b.end(),x)-b.begin();
        int idy=lower_bound(b.begin(),b.end(),y)-b.begin();
        long long sum=0;
        if(pos[idx].empty() || pos[idy].empty()){
            cout<<0<<'\n';
            continue;
        }

        if(mp.find({x,y})!=mp.end()){
            cout<<mp[{x,y}]<<'\n';
            continue;
        }
        if((pos[idx].size())<(pos[idy].size())){
            vector<int> c=pos[idy];
            for(int i=0;i<pos[idx].size();i++){
                
                auto it=lower_bound(c.begin(),c.end(),pos[idx][i]);
                if(it==c.end()) break;
                long long ps=it-c.begin();
                long long cnt=c.size()-ps;
                sum+=cnt;
            }
        }
        else{
            vector<int> c=pos[idx];
            for(int i=0;i<pos[idy].size();i++){
                auto it=lower_bound(c.begin(),c.end(),pos[idy][i]);
                long long cnt=0;
                if(it==c.end()){
                    cnt+=c.size();
                    sum+=cnt;
                    continue;
                }
                long long ps=it-c.begin();
                cnt=ps;
                sum+=cnt;
            }
        }
        mp[{x,y}]=sum;
        cout<<sum<<'\n';

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}