#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

void solve(){
    string s,t;
    cin>>s>>t;
    if(s==string(s.size(),'*')){
        cout<<t.size()*(t.size()+1)/2<<'\n';
        return;
    }//特判全为*
    vector<string> parts;
    if(s[0]=='*'){
        parts.push_back("");
    } 
    for(int l=0,r=0;r<=s.size();r++){
        if(s[r]=='*' || r==s.size()){
            string tmp=s.substr(l,r-l);
            if(tmp!=""){
                parts.push_back(tmp);
            }
            l=r+1;
        }
    } 
    if(s.back()=='*') parts.push_back(""); //分块
    vector<vector<pair<int,int>>> pos(parts.size()); //预处理所有part出现的起止位置
    vector<vector<pair<int,int>>> next(parts.size(),vector<pair<int,int>>(t.size()+1,{inf,inf}));
    for(int k=0;k<parts.size();k++){
        auto &part=parts[k];
        vector<int> pre(part.size()+1,0);
        for(int i=1,j=0;i<part.size();i++){
            while(j && part[i]!=part[j]) j=pre[j];
            if(part[i]==part[j]) j++;
            pre[i+1]=j;
        }
        if(part=="") pos[k].push_back({0,0});
        for(int i=0,j=0;i<t.size();i++){
            while(j && part[j]!=t[i]) j=pre[j];
            if(part[j]==t[i]) j++;
            if(j==part.size()){
                pos[k].push_back({i-j+1,i+1});
                j=pre[j];
            }
        }
        for(auto [l,r]:pos[k]){
            next[k][l]={l,r};
        }
        for(int i=t.size()-1;i>=0;i--){
            next[k][i]=min(next[k][i],next[k][i+1]);

        }
    }


    vector<int> cntr(t.size()+1);
    for(auto [l,r]: pos.back()){
        cntr[l]++;
    }

    if(parts.size()>1){
        for(int i=t.size()-1;i>=0;i--){
            cntr[i]+=cntr[i+1];
        }
    }
    long long res=0;
    for(auto [l,r]:pos[0]){
        for(int k=1;k<pos.size();k++){
            tie(l,r)=next[k][r];
            if(l==inf) break;
        }
        if(l!=inf){
            res+=cntr[l];
        }

    }
    cout<<res<<'\n';
}

int main() {

    solve();

    return 0;
    
}
