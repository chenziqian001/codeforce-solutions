#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    long long l, r;
    cin >> n >> l >> r;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i];
    }
    if(n%2==0){
        n++;
        a.push_back(pre[n/2]);
        pre.push_back(pre.back()^pre[n/2]);
    }
    
    int p=pre[n];
    function<int(long long)> get=[&](long long x)->int{
        if(x<=n) return a[(int)x];
        long long hf=x/2;
        if(hf<=n) return pre[hf];
        if(hf%2==0){
            return p^get(hf);
        }
        else return p;

    };
    cout<<get(l)<<'\n';
   
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    system("pause");
    return 0;
}
