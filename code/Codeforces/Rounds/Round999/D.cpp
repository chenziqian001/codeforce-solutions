#include<bits/stdc++.h>
using namespace std;






void solve(){
    int n,m;
    cin>>n>>m;
    multiset<int> a;
    multiset<int> b;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a.insert(x);
    }
    for(int i=0;i<m;i++) {
        int x;
        cin>>x;
        b.insert(x);
    }

    function<bool(int)> fuck=[&](int v){
        if(v<=0) return false;
        if(v<*a.begin()){
            return false;
        }
        auto it = a.find(v);
        if(it != a.end()){
            a.erase(it);
            return true;
        }
        if(v==1) return false;

        bool res1=true;
       
        int v1=(v+1)/2;
        int v2=v/2;



        res1=res1&&fuck(v1);
        res1=res1&&fuck(v2);
        return res1;
    };


    while(true){
        int num=*b.begin();
        b.erase(b.begin());
        if(!fuck(num)){
            cout<<"NO"<<'\n';
            return;
        }
        if(b.empty() && a.empty()){
            cout<<"YES"<<'\n';
            return;
        }
        else if(b.empty() || a.empty()){
            cout<<"NO"<<'\n';
            return;
        }
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