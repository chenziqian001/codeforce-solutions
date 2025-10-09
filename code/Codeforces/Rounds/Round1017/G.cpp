#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int t;
    cin>>t;
    int size=0;
    int sum=0;
    deque<int> q;
    deque<int> rq;
    int q_val=0;
    int rq_val=0;
    
    while(t--){
        int op;
        cin>>op;
        if(op==1){
            int val=q.back();
            q.pop_back();
            q.push_front(val);
            rq.pop_front();
            rq.push_back(val);
            q_val=q_val-val*size+sum;
            rq_val=rq_val+val*size-sum;
        }
        else if(op==2){
            swap(q_val,rq_val);
            swap(q,rq);
        }
        else{
            int v;
            cin>>v;
            size++;
            sum+=v;
            q.push_back(v);
            rq.push_front(v);
            q_val+=size*v;
            rq_val+=sum;            
        }

        cout<<q_val<<'\n';
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    system("pause");
    return 0;
}