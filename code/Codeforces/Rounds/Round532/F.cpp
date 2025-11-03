#include<bits/stdc++.h>
using namespace std;
#define int long long


class basis{
    static constexpr int K=51;
    int a[K];
    int t[K];

public:
    basis() :a{} ,t{} {}

    void insert(int x,int time){
        for(int i=K-1;i>=0;i--){
            if((x>>i)&1){
                if(time>t[i]){
                    swap(a[i],x);
                    swap(t[i],time);
                }
                x^=a[i];
            }
        }
    }

    int query(int j) const {
        int res=0;
        for(int i=K-1;i>=0;i--){
            if(t[i]>=j &&((res^a[i])>res)){
                res^=a[i];
            }
        }
        return res;
    }

};



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int q;
    cin>>q;

    vector<int> id(q);
    iota(id.begin(),id.end(),0);
    vector<pair<int,int>> qe(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        qe[i]={l,r};
    }
    sort(id.begin(),id.end(),[&](int x,int y){
        return qe[x].second<qe[y].second;
    });//离线并按右端点升序
    basis ba;
    vector<int> res(q);
    int j=0;
    for(int i=1;i<=n;i++){
        ba.insert(a[i],i);
        while(j<q && i==qe[id[j]].second){
            res[id[j]]=ba.query(qe[id[j]].first);
            j++;
        }
    }  
    for(int x:res){
        cout<<x<<'\n';
    }
    //system("pause");
    

}