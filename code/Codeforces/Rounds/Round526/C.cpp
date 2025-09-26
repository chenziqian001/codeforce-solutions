#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main(){
    string ss;
    cin>>ss;
    string s;
    int n=ss.size();
    for(int i=0;i<n;i++){
        if(ss[i]=='b'){
            if(!s.empty() && s.back()!='b'){
                s+=ss[i];
            }
        }
        else{
            if(ss[i]=='a'){
                s+=ss[i];
            }
        }
    }
    int m=s.size();
    vector<int> gp;
    int cnt=0;
    for(int i=0;i<m;i++){
        if(s[i]=='b'){
            if(cnt) gp.push_back(cnt);
            cnt=0;
        }
        else cnt++;
    }
    gp.push_back(cnt);
    int res=1;
    for(int x:gp){
        res=(res*(x+1)%mod)%mod;
    }
    res=(res-1)%mod;


    cout<<res<<'\n';
    system("pause");
    return 0;
}



