#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;




void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++) cin>>a[i][j];
    }
    set<int> candi;
    set<int> rm;
    vector<int> res;
    for(int i=0;i<n;i++) candi.insert(i);
    rm=candi;
    for(int i=0;i<N;i++){
        bool flag=false;
        for(int id:candi){
            if((int)a[id].size() <=i){
                flag=true;
                break;
            }
        }
        if(flag){
            set<int> nrm;
            for(int id:rm){
                if(a[id].size()>i){
                    nrm.insert(id);
                }
            }
            candi=nrm;
            rm=nrm;
        }

        if(candi.size()==0) break;
        int mini=N;
        for(int id:candi){
            mini=min(mini,a[id][i]);
        }
        res.push_back(mini);
        vector<int> remove; 
        for(int id:candi){
            if(a[id][i]!=mini){
                remove.push_back(id);
            }
        }
        for(int id:remove){
            candi.erase(id);
        }

    }


    for(int x:res){
        cout<<x<<" ";
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