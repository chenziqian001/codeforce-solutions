#include<bits/stdc++.h>
using namespace std;
int n,k;

void get(const string &base,vector<int> &pi){
    int m=base.size();
    pi.resize(m);
    pi[0]=0;
    int k=0;
    for(int q=1;q<m;q++){
        while(k>0 && base[k]!=base[q]){
            k=pi[k-1];
        }
        if(base[k]==base[q]){
            k++;
        }
        pi[q]=k;
    }
}
bool check(string s,int m){
    if(m==0) return true;
    string base=s.substr(0,m);
    int len=base.size();
    vector<int> pi;
    get(base,pi);
    int cnt=1;
    int cur=0;
    for(int i=len;i<s.size();i++){
        while(cur>0 && s[i]!=base[cur]){
            cur=pi[cur-1];
        }
        if(s[i]==base[cur]){
            cur++;
        }
        if(cur==len){
            cnt++;
            cur=0;
        }
        if(cnt>=k) return true;

    }
    return cnt>=k;
}



void solve(){
    int l,r;
    cin>>n>>l>>r;
    k=r;
    string s;
    cin>>s;
    int L=0,R=n/k;
    int res=0;
    while(L<=R){
        int mid=(L+R)/2;
        if(check(s,mid)){
            res=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}



