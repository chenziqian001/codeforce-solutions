#include<bits/stdc++.h>
using namespace std;
const int N=5100000;
int lpf[N];
int last[5032108][8];
void getlpf(){
    for(int i=2;i<N;i++){
        if(!lpf[i]){
            for(int j=i;j<N;j+=i){
                if(!lpf[j]) lpf[j]=i;
            }
        }
    }
}
struct query{
    int l,id;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getlpf();
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<query>> Q(n);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        r--;
        Q[r].push_back({l,i});
    }
    vector<int> ans(q,0);
    vector<int> ps(15,0);
    for(int i=0;i<n;i++){
        int x=a[i];
        vector<int> divi;
        while(x>1){
            int p=lpf[x];
            int cnt=0;
            while(x%p==0){
                x/=p;
                cnt++;
            }
            if(cnt%2==1) divi.push_back(p);
        }
       

        int w=divi.size();
        int sz=1<<w;
        vector<int> sub(sz);
        sub[0]=1;

        for(int st=1;st<sz;st++){
            int c=__builtin_ctz(st);
            int pre=st^(1<<c);
            sub[st]=sub[pre]*divi[c];
        }
        for(int st=0;st<sz;st++){
            int com=__builtin_popcount(st);
            int mul=sub[st];
            for(int w2=com;w2<=7;w2++){
                int op=w+w2-2*com;
                ps[op]=max(ps[op],last[mul][w2]);
            }
            last[mul][w]=i+1;
        }
        
        for(auto [l,id]:Q[i]){
            for(int op=0;op<=14;op++){
                if(ps[op]>=l){
                    ans[id]=op;
                    break;
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
