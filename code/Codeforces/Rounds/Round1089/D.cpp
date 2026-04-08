#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;


    auto get1=[&](string s){
        vector<int> a(n);
        stack<int> st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                st.push(i);
            }
            else{
                int id=st.top();
                st.pop();
                a[id]=i;
                a[i]=id;
            }
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(a[i]==n-i-1){
                res++;
            }
            else break;
        }
        return res;
    };

    auto get2=[&](string s){
        int res=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='(' && s[i+1]==')'){
                res++;
            }
        }
        return res;
    };


    if(get1(s)==get1(t) && get2(s)==get2(t)){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';


    

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
