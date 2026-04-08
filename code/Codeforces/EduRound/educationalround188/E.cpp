#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    cin>>s;

    int n=s.size();

    if(n==1){
        cout<<s<<'\n';
        return;
    }
    vector<int> cnt(10);
    int sum=0;
    for(char c:s){
        cnt[c-'0']++;
        sum+=(c-'0');
    }

    int up=9*n;
    for(int y=1;y<=up;y++){
        vector<int> tmp=cnt;
        string tail;

        int x=y;
        while(1){
            int nx=0;
            string snx=to_string(x);
            tail+=snx;
            for(char c:snx){
                tmp[c-'0']--;
                nx+=c-'0';
            }
            if(x<=9) break;
            x=nx;
        }


        bool ok=true;
        for(int i=0;i<=9;i++){
            if(tmp[i]<0){
                ok=false;
            }
        }
        if(!ok) continue;


        int tt=0;
        for(int i=0;i<=9;i++){
            tt+=i*tmp[i];
        }
        if(tt!=y) continue;
        for(int i=9;i>=0;i--){
            for(int j=0;j<tmp[i];j++){
                cout<<i;
            }
        }
        cout<<tail<<'\n';
        return;
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