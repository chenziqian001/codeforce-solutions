#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    vector<int> z(n);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i]){
            l=i;
            r=i+z[i];
            z[i]++;
        }
    }
    set<int> st;
    int mx_len=0;
    for(int i=n-1;i>=1;i--){
        auto it=st.upper_bound(z[i]);
        if(it!=st.begin()){
            --it;
            mx_len=max(mx_len,*it);
        }
        if(z[i]==n-i){
            st.insert(z[i]);
        }
    }
    if(mx_len==0){
        cout<<"Just a legend"<<'\n';
    } else {
        cout<<s.substr(0,mx_len)<<'\n';
    }
}