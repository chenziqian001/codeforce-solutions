#include<bits/stdc++.h>
using namespace std;
 
/*
void solve1(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    vector<int> b(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[i]=u;
        b[i]=v;
    }
    if(n>=20){
        cout<<n<<'\n';
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<'\n';
        return;
    }
    int ans=-1;
    auto check=[&](int s){
        if(__builtin_popcount(s)>n/5) return;
        for(int i=1;i<=n;i++){
            if(s>>i&1){
                for(int j=i*2;j<=n;j+=i){
                    s^=(1<<j);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(s >> a[i] & ~s >> b[i] & 1) return;
        }
        ans=s;
    };
    for(int x=1;x<=n;x++){
        check(1<<x);
        for(int y=x+1;y<=n;y++){
            check(1<<x | 1<<y);
            for(int z=y+1;z<=n;z++){
                check(1<<x | 1<<y | 1<<z);
            }
        }
    }
    if(ans==-1){
        cout<<-1<<'\n';
        return;
    }
    cout<<__builtin_popcount(ans)<<'\n';
    for(int i=1;i<=n;i++){
        if(ans>>i&1){
            cout<<i<<" ";
        }
    }
    cout<<'\n';
    
}//说实话这种做法我不完全明白，check函数的逻辑太诡异了
*/
//所以我决定再写一个solve2
vector<vector<int>> all;

void solve2(){
    int n,m;
    cin>>n>>m;
    vector<int> u(m);
    vector<int> v(m);
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i];
        u[i]--,v[i]--;
    }
    if(n>19){
        cout<<n<<'\n';
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<'\n';
        return;
    }
    vector<int> imp(n);
    bool found=false;
    for(int i=0;i<m;i++){
        imp[u[i]]|=(1<<v[i]);
    }
    for(int t:all[n]){
        bool ok=true;
        for(int i=0;i<n;i++){
            if(t&(1<<i)){
                if((t & imp[i]) !=imp[i]){
                    ok=false;
                    break;
                }
               
            }
        }
        if(ok){
            vector<int> res;
            for(int i=0;i<n;i++){
                if(t>>i&1) res.push_back(i+1);
            }
            cout<<res.size()<<'\n';
            for(int x:res){
                cout<<x<<" ";
            }
            cout<<'\n';
            found=true;
            break;
        }
    }
    if(!found){
        cout<<-1<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    all.resize(20);
    for(int n=1;n<20;n++){
        for(int t=1;t<(1<<n);t++){
            int mask=0;
            for(int i=1;i<=n;i++){
                if(t&(1<<(i-1))){
                    for(int j=i;j<=n;j+=i){
                        mask^=(1<<(j-1));
                    }
                }
            }
            if(__builtin_popcount(mask)<=n/5) all[n].push_back(t);
        }
    }//预处理所有按钮按法
    int t;
    cin>>t;
    while(t--) solve2();
    return 0;
}