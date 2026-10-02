#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;


    int cnt=0;
    int l=0,r=n-1;
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++,r--;
    }
    string res="";
    for(int i=0;i<=n;i++){
        if(i<cnt || i>n-cnt){
            res+='0';
        }
        else if(i==cnt){
            res+='1';
        }
        else{
            int ex=i-cnt;
            if(ex%2==1){
                if(n%2==1){
                    res+='1';
                }
                else{
                    res+='0';
                }
            }
            else {
                res+='1';
            }

        }

    }
    cout<<res<<'\n';


    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    //system("pause");
    return 0;
}

