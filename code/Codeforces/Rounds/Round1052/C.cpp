#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;


    for(int i=0;i<n;i++){
        if(n>=2){
            if(i==0 && s[i]=='0' && s[i+1]=='1'){
                cout<<"NO"<<'\n';
                return;
            }
            if(i==n-1 && s[i]=='0' && s[i-1]=='1'){
                cout<<"NO"<<'\n';
                return;
            }
        }
        if(i>0 && i<n-1){
            if(s[i]=='0' && s[i-1]=='1' && s[i+1]=='1'){
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    vector<int> res(n);
    for(int i=0;i<n;i++){
        res[i]=i+1;
    }


    vector<int> pos;
    pos.push_back(-1);
    for(int i=0;i<n;i++){
        if(s[i]=='1') pos.push_back(i);
    }
    pos.push_back(n);
    int m=pos.size();
    for(int i=1;i<m;i++){
        int cur=pos[i];
        int pre=pos[i-1];
        if(pre+1==cur) continue;
        swap(res[pre+1],res[cur-1]);
    }
    
    cout<<"YES"<<'\n';

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
    

}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}