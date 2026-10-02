#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> cnta(n+1);
    vector<int> cntb(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        cnta[a[i]]++;
        cntb[b[i]]++;
    }
    vector<int> id(n);
    iota(id.begin(),id.end(),0);
    int res=0;
    while(!id.empty()){
        vector<int> nid;
        int mxa=*max_element(cnta.begin(),cnta.end());
        int mxb=*max_element(cntb.begin(),cntb.end());
        if(mxa>mxb){
            for(int i=0;i<=n;i++){
                if(cnta[i]==mxa){
                    cnta[i]=0;
                    for(int x:id){
                        if(a[x]!=i){
                            nid.push_back(x);
                        }
                        else{
                            cntb[b[x]]--;
                        }
                    }
                    break;
                }
            }
        }
        else{
            for(int i=0;i<=n;i++){
                if(cntb[i]==mxb){
                    cntb[i]=0;
                    for(int x:id){
                        if(b[x]!=i){
                            nid.push_back(x);
                        }
                        else{
                            cnta[a[x]]--;
                        }
                    }
                    break;
                }
            }
        }
        if(nid.empty()) break;
        res+=max(mxa,mxb)+1;
        id=nid;
    }
    cout<<res<<'\n';



    


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