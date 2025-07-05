#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> prev,cur;
    int res=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        prev.insert(a[i]);
        cur.insert(a[i]);
        if(cur.size()==prev.size()){
            res++;
            cur.clear();
        }

    }
    cout<<res<<'\n';
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}