#include<bits/stdc++.h>
using namespace std;

vector<int> getdiff(const vector<int> &a){
    int n=a.size();
    vector<int> res(n-1);
    for(int i=0;i<n-1;i++){
        res[i]=a[i+1]-a[i];
    }
    return res;
}

vector<int> bdlps(const vector<int> &a){
    int m=a.size();
    vector<int> res(m,0);
    for(int i=1;i<m;i++){
        int j=res[i-1];
        while(j>0 && a[i]!=a[j]) j=res[j-1];
        if(a[i]==a[j]) j++;
        res[i]=j;

    }
    return res;
}




void solve(){
    int n,w;
    cin>>n>>w;
    vector<int> a(n);
    vector<int> b(w);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<w;i++) cin>>b[i];
    if(n<w){
        cout<<0<<'\n';
        return;
    }
    if(w==1){
        cout<<n<<'\n';
        return;
    }
    vector<int> da=getdiff(a);
    vector<int> db=getdiff(b);
    vector<int> all_diff;
    for(int i=0;i<n-1;i++){
        all_diff.push_back(da[i]);
    }
    for(int i=0;i<w-1;i++){
        all_diff.push_back(db[i]);
    }
    sort(all_diff.begin(),all_diff.end());
    all_diff.erase(unique(all_diff.begin(),all_diff.end()),all_diff.end());
    for(int i=0;i<n-1;i++){
        int idx=lower_bound(all_diff.begin(),all_diff.end(),da[i])-all_diff.begin();
        da[i]=idx;
    }
    for(int i=0;i<w-1;i++){
        int idx=lower_bound(all_diff.begin(),all_diff.end(),db[i])-all_diff.begin();
        db[i]=idx;
    }
    int x=db.size();
    int y=da.size();

    db.push_back(-1);
    db.insert(db.end(),da.begin(),da.end());
    vector<int> lps=bdlps(db);

    int res=0;
    for(int i=x+1;i<=x+y;i++){
        if(lps[i]==x) res++;

    }



    cout<<res<<'\n';
    

}


int main(){
    solve();
    system("pause");
    return 0;
}




