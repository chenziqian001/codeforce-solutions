#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int x){
    cout<<x<<endl;
    int y;
    cin>>y;
    return y;
}


void solve() {
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }

    int mex=0;
    for(int x:s){
        if(x==mex){
            mex++;
        }   
        else{
            break;
        }
    }
    while(true){
        int y=ask(mex);
        if(y<0){
            return;
        }
        else{
            mex=y;
        }
    }
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    //system("pause");
    return 0;
}