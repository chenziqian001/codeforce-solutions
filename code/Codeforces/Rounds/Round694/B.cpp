#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int mp[N];


void init() {
    for (int i = 2; i < N; i++) {
        if (!mp[i]) {
            for (int j = i; j < N; j += i) {
                if (!mp[j]) mp[j] = i;
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> p(n);
    for(int i=0;i<n;i++){
        int x=a[i];
        while(x>1){
            int pp=mp[x];
            int cnt=0;
            while(x%pp==0){
                x/=pp;
                cnt++;
            }
            if(cnt%2==1){
                p[i].push_back(pp);
            }
        }
    }
    sort(p.begin(),p.end());
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;){
        int j=i;
        while(j<n && p[i]==p[j]){
            j++;
        }
        ans1=max(ans1,j-i);
        if(p[i].empty() || (j-i)%2==0){
            ans2+=(j-i);
        }
        i=j;
    }
    ans2=max(ans1,ans2);
    int q;
    cin>>q;
    while(q--){
        long long w;
        cin>>w;
        if(w==0LL){
            cout<<ans1<<'\n';
        }
        else{
            cout<<ans2<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}