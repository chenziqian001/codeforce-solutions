#include<bits/stdc++.h>
using namespace std;

bool valid(map<int,int> &mp){
    if(mp.size()>2) return false;
    else if(mp.size()==1) return true;
    auto it=mp.begin();
    pair<int,int> x=*it;
    it++;
    pair<int,int> y=*it;
    if(min(x.second,y.second)==1){
        return true;
    }
    else return false;
}
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> len(n,1);
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            len[i]=len[i-1]+1;
        }
    } //正向长度
    vector<int> ilen(n,1);
    for(int i=n-2;i>=0;i--){
        if(s[i]==s[i+1]){
            ilen[i]=ilen[i+1]+1;
        }
    } //反向长度
    vector<map<int,int>> itype(n); //统计长度种类对应个数
    for(int i=n-1;i>=0;i--){
        if(i!=n-1){
            itype[i]=itype[i+1];
        }
        if(i==0 || s[i]!=s[i-1]){
            itype[i][ilen[i]]++;
        }
    }
    vector<map<int,int>> type(n);

    for(int i=0;i<n-1;i++){
        int stan=ilen[i+1];
        int now_len=len[i];
        int comb_len=now_len+len[n-1];
        itype[i+1]

    }


}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}


