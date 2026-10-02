#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    int mxi=-1e9,mni=1e9,mxj=-1e9,mnj=1e9;
    int mxs=-1e9,mns=1e9,mxa=-1e9,mna=1e9;
    int c=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<n;j++){
            if(s[i][j]=='#'){
                c++;
                mxi=max(mxi,i); mni=min(mni,i);
                mxj=max(mxj,j); mnj=min(mnj,j);
                mxs=max(mxs,i-j); mns=min(mns,i-j);
                mxa=max(mxa,i+j); mna=min(mna,i+j);
            }
        }
    }
    if(c==0){
        cout<<"YES"<<'\n';
        return;
    }
    if((mxi-mni<=1 && mxj-mnj<=1) || (mxs-mns<=1) || (mxa-mna<=1)) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;

}


