#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<string> o1(n,""),o2(n,""),res(n,"");
    map<string,int> c;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        o1[i]=a.substr(0,3);
        o2[i]=a.substr(0,2)+b.substr(0,1);
        c[o1[i]]++;
    }
    for(int i=0;i<n;i++){
        if(c[o1[i]]>1){
            res[i]=o2[i];
        }
    }

    bool ok=true;
    while(ok){
        ok=false;
        for(int i=0;i<n;i++){
            if(res[i]==""){
                for(int j=0;j<n;j++){
                    if(i!=j && res[j]==o1[i]){
                        ok=true;
                        res[i]=o2[i];
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(res[i]=="") res[i]=o1[i];
    }
    set<string> st;
    for(int i=0;i<n;i++){
        if(st.count(res[i])){
            cout<<"NO"<<'\n';
            return;
        }
        else st.insert(res[i]);
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<n;i++){
        cout<<res[i]<<'\n';
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