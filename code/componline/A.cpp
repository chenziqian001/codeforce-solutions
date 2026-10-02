#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    string s;
    vector<int> a;
    set<int> st;
    
    
    for(int i=0;i<n;i++){
        char op;
        int x;
        cin>>op>>x;
        if(op=='+'){
            while(!a.empty() && st.count(x)){
                st.erase(a.back());
                a.pop_back();
                s+='-';
            }
            a.push_back(x);
            s+='+';
            st.insert(x);
        }
        else if(op=='F'){
            while(!a.empty() && st.count(x)){
                st.erase(a.back());
                a.pop_back();
                s+='-';
            }
            s+='?';
        }
        else if(op=='T'){
            s+='?';
        }
    }
    cout<<s<<'\n';
}

signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

