#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),o,e;

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0)o.push_back(a[i]);
        else e.push_back(a[i]);
    }
    
    auto get_inv=[&](vector<int>& v){
        vector<int> bit(n+1,0);
        long long inv=0;
        for(int i=0;i<v.size();i++){
            int sum=0;
            for(int j=v[i];j>0;j-=j&-j)sum+=bit[j];
            inv+=i-sum;
            for(int j=v[i];j<=n;j+=j&-j)bit[j]+=1;
        }
        return inv%2;
    };

    int pO=get_inv(o);
    int pE=get_inv(e);

    sort(o.begin(),o.end());
    sort(e.begin(),e.end());

    auto build=[&](vector<int> x,vector<int> y){
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i%2==0)res.push_back(x[i/2]);
            else res.push_back(y[i/2]);
        }
        return res;
    };
    
    if(pO==pE){
        vector<int> res=build(o,e);
        for(int i=0;i<n;i++)cout<<res[i]<<" \n"[i==n-1];
    }else{
        
        vector<int> o2=o,e2=e;
        swap(o2[o2.size()-1],o2[o2.size()-2]);
        swap(e2[e2.size()-1],e2[e2.size()-2]);
    
        vector<int> c1=build(o2,e);
        vector<int> c2=build(o,e2);
        vector<int> res=min(c1,c2);
        for(int i=0;i<n;i++)cout<<res[i]<<" \n"[i==n-1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}