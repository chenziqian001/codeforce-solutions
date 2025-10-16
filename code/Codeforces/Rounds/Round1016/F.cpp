#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i]=s;
    }
    set<string> st;
    vector<vector<string>> b(m,vector<string>(n));
    int mx=0;
    vector<int> ap(n,false);
    for(int i=0;i<m;i++){
        int cur=0;
        for(int j=0;j<n;j++){
            string s;
            cin>>s;
            b[i][j]=s;
            st.insert(s);
            if(s==a[j]){
                cur++;
                ap[j]=true;
            }
        }
        mx=max(mx,cur);
    }
    for(int i=0;i<n;i++){
        if(!ap[i]){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<n+(n-mx)*2<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}