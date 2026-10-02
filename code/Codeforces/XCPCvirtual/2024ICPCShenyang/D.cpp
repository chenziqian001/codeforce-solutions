#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    auto get_inv=[&](vector<int> v)->int{
        int res=0;
        vector<int> fw(n+1);
        auto add=[&](int pos,int val){
            for(int i=pos;i<=n;i+=i&-i) fw[i]+=val;
        };
        auto query=[&](int pos)->int{
            int res=0;
            for(int i=pos;i>0;i-=i&-i) res+=fw[i];
            return res;
        };
        for(int i=0;i<n;i++){
            res+=query(n)-query(v[i]-1);
            add(v[i],1);
        }
        return res;
    };
    string ans="";
    int ia=get_inv(a);
    int ib=get_inv(b);
    if(ia%2==ib%2) ans+='B';
    else ans+='A';
    for(int i=0;i<n-1;i++){
        char c;
        cin>>c;
        int l,r,d;
        cin>>l>>r>>d;
        if(c=='A'){
            int ni=d*(r-l)%2;
            ia=(ia+ni)%2;
        }
        else if(c=='B'){
            int ni=d*(r-l)%2;
            ib=(ib+ni)%2;
        }
        if(ia%2==ib%2) ans+='B';
        else ans+='A';
    }
    cout<<ans<<'\n';


    
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
 
 