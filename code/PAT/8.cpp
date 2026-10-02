#include<bits/stdc++.h>
using namespace std;
#define int long long

int check(string a,string b,int pos){
    int m=b.size();
    bool ok=1;
    if(pos+m>a.size()){
        return 0;     
    }
    for(int i=pos;i<pos+m;i++){
        if(a[i]!=b[i-pos]){
            ok=0;
        }
    }
    return ok;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0;i<n;i++){
        int op;
        cin>>op;
        if(op==1){
            vector<int> pos;
            string t;
            cin>>t;

            for(int i=0;i<s.size();i++){
                if(check(s,t,i)==1){
                    pos.push_back(i);
                }
            }
            int sz=min(3LL,(int)pos.size());
            if(sz==0){
                cout<<-1<<'\n';
                continue;
            }
            for(int i=0;i<sz;i++){
                cout<<pos[i];
                if(i!=sz-1){
                    cout<<" ";
                }
            }
            cout<<'\n';
        }
        else if(op==2){
            int p;
            string t;
            cin>>p>>t;
            string res;
            for(int i=0;i<p;i++){
                res+=s[i];
            }
            res+=t;
            for(int i=p;i<s.size();i++){
                res+=s[i];
            }
            s=res;
            cout<<res<<'\n';
        }
        else{
            int l,r;
            cin>>l>>r;
            vector<char> v(s.size());
            for(int i=0;i<s.size();i++){
                v[i]=s[i];
            }
            int len=l+r;
            for(int i=l;i<=r;i++){
                v[i]=s[len-i];
            }
            for(int i=0;i<s.size();i++){
                s[i]=v[i];
            }
            cout<<s<<'\n';
        }
    }
    
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}