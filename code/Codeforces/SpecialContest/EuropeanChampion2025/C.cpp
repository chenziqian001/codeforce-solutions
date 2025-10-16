#include<bits/stdc++.h>

using namespace std;




void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    multiset<int> s(a.begin(),a.end());
    int gp=0;
    while(!s.empty()){
        int m=*s.begin();
        s.erase(s.begin());
        bool ok=(m<k);
        if(!s.empty() && ok){
            auto that=prev(s.end());
            s.erase(that);
            
        }
        if(!s.empty() && ok){
            auto it =s.lower_bound(k-m);
            if(it!=s.begin()) it--;
            if(m+*it<k) s.erase(it);
        }
        gp++;
    }

    cout<<gp-1<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}