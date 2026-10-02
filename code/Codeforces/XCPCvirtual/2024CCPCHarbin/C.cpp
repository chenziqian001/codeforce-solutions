#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<pair<char,int>> a;
    char st='?';
    char pre='?';
    
    map<char,pair<char,char>> comp={{'N',{'W','E'}},{'S',{'E','W'}},{'E',{'N','S'}},{'W',{'S','N'}}};
    for(int i=0;i<n;i++){
        char d;
        int len;
        cin>>d>>len;
        if(i==0){
            st=d;
            pre=d;
            a.push_back({'Z',len});
            continue;
        }
        else{
            if(d==comp[pre].first){
                a.push_back({'L',-1});
                a.push_back({'Z',len});
            }   
            else{
                a.push_back({'R',-1});
                a.push_back({'Z',len});
            }         
        }
        pre=d;
    }
    cout<<a.size()<<" "<<st<<'\n';
    for(auto [x,y]:a){
        if(y==-1){
            cout<<x<<'\n';
        }
        else{
            cout<<x<<" "<<y<<'\n';
        }
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


