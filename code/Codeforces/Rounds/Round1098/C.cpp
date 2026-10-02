#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


void solve(){
   int a,n;
    cin>>a>>n;
    vector<int> d(n);
    for(int i=0;i<n;i++)cin>>d[i];
    string s=to_string(a);
    int len=s.size();
    int mn=d[0],mx=d.back();
    int mnn=-1;
    for(int x:d)if(x>0){mnn=x;break;}

    int res=1e18;
    auto upd=[&](string t){
        if(t.size()&&t.size()<=18){
            res=min(res,abs(a-stoll(t)));
        }
    };

    if(mnn!=-1) upd(to_string(mnn)+string(len,mn+'0'));
    else upd("0");


    if(len>1){
        if(mx>0)upd(string(len-1,mx+'0'));
        else if(len==2)upd("0");
    }
    string p="";

    for(int i=0;i<len;i++){
        int c=s[i]-'0';
        int lv=-1,gv=-1;
        for(int x:d){
            if(x<c)lv=x;
            if(x>c&&gv==-1)gv=x;
        }
        if(lv!=-1){
            if(!(i==0 && lv==0 && len>1))upd(p+to_string(lv)+string(len-1-i,mx+'0'));
        }
        if(gv!=-1)upd(p+to_string(gv)+string(len-1-i,mn+'0'));
        
        bool ok=0;
        for(int x:d)if(x==c)ok=1;
        if(!ok)break;
        p+=to_string(c);
        if(i==len-1) upd(p);
    }
    cout<<res<<'\n';



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