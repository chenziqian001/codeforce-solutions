#include<bits/stdc++.h>
using namespace std;
#define int long long




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);   
    string s;
    cin>>s;
    s=" "+s;
    
    vector<bitset<100005>> b(26);
    for(int i=1;i<s.size();i++){
        b[s[i]-'a'][i]=1;
    }

    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int pos;
            char c;
            cin>>pos>>c;
            b[s[pos]-'a'][pos]=0;
            s[pos]=c;
            b[c-'a'][pos]=1;
        }
        else{
            int l,r;
            string x;
            cin>>l>>r>>x;

            if(r-l+1<x.size()){
                cout<<0<<'\n';
                continue;
            }
            bitset<100005> res=b[x[0]-'a'];
            for(int i=1;i<x.size();i++){
                res&=(b[x[i]-'a']>>i);
            }
            int len=r-x.size()+2-l; 
            res>>=l;
            res<<=(100005-len);
            //res>>=(100005-len);
            cout<<res.count()<<'\n';
        }
    }
    //system("pause");
    return 0;
}