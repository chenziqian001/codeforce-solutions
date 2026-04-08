#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    int pos=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            pos=i;
            cnt++;
        }
    }
    if(pos==-1){
        int res=1;
        for(int i=4;i<n;i+=3){
            res++;
        }
        if((n-2)>=0){
            if((n-2)%3==2) res++;
        }
        cout<<res<<'\n';
    }
    else{
        int res=cnt;
        vector<int> d;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(i-prev-1) d.push_back(i-prev-1);
                prev=i;
            }
        }
        if(n-prev-1) d.push_back(n-prev-1);
        for(int i=0;i<d.size();i++){
            int x=d[i];
            if((i==0 && s[0]=='0') || (i==(d.size()-1) && (n-prev-1))){
                if(x==1){
                }
                else{
                    res+=((x-2)/3)+1;
                }
            }
            else{
                if(x==1 || x==2){
                }
                else{
                    res+=((x-3)/3)+1;
                }
            }
        }
        cout<<res<<'\n';
    }
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

