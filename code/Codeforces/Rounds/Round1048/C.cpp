#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int k,x;
    cin>>k>>x;
    int cc=x,cv=(1LL<<(k+1))-x;
    int init=1LL<<k;
    vector<int> res;
    while(cc!=init){
        if(cc>init){
            res.push_back(2);
            cc-=cv;
            cv*=2;
        }
        else{
            res.push_back(1);
            cv-=cc;
            cc*=2;
        }
    }

    reverse(res.begin(),res.end());
    int n=res.size();
    cout<<n<<"\n";
    for(int r:res) cout<<r<<" ";
    cout<<'\n';


}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}