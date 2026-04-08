#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> A(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        A[a[i]]=i;
    }

   
    vector<int> p(n+1),q(n+1);

    if(n<=3) {
        iota(q.begin() + 1, q.end(), 1);
        bool found = false;
        do {
            bool ok = true;
            for(int i=1;i<=n;i++) {
                if(q[i]==i || q[i]==A[i]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                for(int i=1;i<=n;i++) p[q[i]] = A[i];
                found = true;
                break;
            }
        } while(next_permutation(q.begin() + 1, q.end()));
        
        if(found) {
            cout << "Possible"<<'\n';
            for(int i=1;i<=n;i++) cout<<p[i]<<" ";
            cout<<"\n";
            for(int i=1;i<=n;i++) cout<<q[i]<<" ";
            cout<<"\n";
        } else {
            cout<<"Impossible"<<'\n';
        }
        return;
    }
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    iota(q.begin() + 1, q.end(), 1);

    while(true){
        shuffle(q.begin()+1,q.end(),rng);
        bool ok=true;
        for(int i=1;i<=n;i++){
            if(q[i]==i || q[i]==A[i]){
                ok=false;
                break;
            }
        }
        if(ok) break;
    }

    for(int i=1;i<=n;i++){
        p[q[i]]=A[i];
    }
    cout<<"Possible"<<'\n';
    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<q[i]<<" ";
    cout<<"\n";
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