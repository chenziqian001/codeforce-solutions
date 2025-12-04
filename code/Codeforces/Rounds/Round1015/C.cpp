#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    map<pair<int,int>,set<int>> mp;
   
    vector<pair<int,int>> res;
    auto change=[&](int psx,int psy){
        
        pair<int,int> p1_old = {min(a[psx], b[psx]), max(a[psx], b[psx])};
        pair<int,int> p2_old = {min(a[psy], b[psy]), max(a[psy], b[psy])};

        
        mp[p1_old].erase(psx);
        mp[p2_old].erase(psy);
        
        
        swap(a[psx],a[psy]);
        swap(b[psx],b[psy]);
        
        
        pair<int,int> p1_new = {min(a[psx], b[psx]), max(a[psx], b[psx])};
        pair<int,int> p2_new = {min(a[psy], b[psy]), max(a[psy], b[psy])}; 


        mp[p1_new].insert(psx); 
        mp[p2_new].insert(psy);
    };

    int same=0;
    int samepos=-1;
    for(int i=0;i<n;i++){
        int x=a[i],y=b[i];
        if(x==y){
            if(same || (n%2==0)){
                cout<<-1<<'\n';
                return;
            }    
            same++;
            samepos=i;
            mp[{x,y}].insert(i);
            continue;
        }
        pair<int,int> p;
        if(x>y){
            swap(x,y);
        }
        p={x,y};
        mp[p].insert(i);
    }

    
    if(same){
        if(samepos!=n/2){
            change(samepos,n/2);
            res.emplace_back(samepos,n/2);
        }

    }

    /*
    for(auto &m:mp){
        cout<<m.first.first<<" "<<m.first.second<<'\n';
        for(int x:m.second) cout<<x<<" ";
        cout<<'\n';
        cout<<"------------------"<<'\n';
    }
    */
    for(auto &m:mp){
        if(m.first.first==m.first.second) continue;
        
        if((m.first.first!=m.first.second) && (m.second.size()==1)){
            cout<<-1<<'\n';
            return;
        }

        int one=*m.second.begin();
        auto it=m.second.begin();
        it++;
        int sec=*it;
        if(one+sec!=n-1){
            int tg=n-1-one;
            change(tg,sec);
            res.emplace_back(sec,tg);
        }
    }
    /*
    cout<<"0000000000000000000000000000000"<<'\n';
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<'\n';
    cout<<"00000000000000000000000000000000000"<<'\n';
    */
    cout<<res.size()<<'\n';
    for(auto [x,y]:res){
        cout<<x+1<<" "<<y+1<<'\n';
    }
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