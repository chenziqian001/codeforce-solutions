#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    unordered_map<int,string> na;
    unordered_map<string,int> naa;
    vector<vector<int>> time1(n,vector<int>(26));
    vector<vector<int>> time2(n,vector<int>(26));
    vector<vector<int>> solve(n,vector<int>(26,0));
    int pos=0;
    for(int i=0;i<n;i++){
        string a,d;
        char b;
        int c;
        cin>>a>>b>>c>>d;
        if(naa.find(a)==naa.end()){
            na[pos++]=a;
            naa[a]=pos-1;
        }
        int id=naa[a];
        if(solve[id][b-'A']==0){
            if(d[0]=='A'){
                time1[id][b-'A']+=c;
                solve[id][b-'A']=1;
            }
            else if(d[0]=='R'){
                time1[id][b-'A']+=c;
                time2[id][b-'A']+=c;
            }
            else{
                solve[id][b-'A']=3;
                time2[id][b-'A']+=c;
            }
        }
    }
    set<int> ans;
    int bc=0;
    int bt=1e5+1;
    for(int i=0;i<pos;i++){
        int cnt=0;
        int t=0;
        for(int j=0;j<26;j++){
            if(solve[i][j]==1){
                cnt++;
                t+=time1[i][j];
            }
        }
        if(cnt>bc){
            bc=cnt;
            bt=t;
            ans.clear();
            ans.insert(i);
        }
        else if(cnt==bc){
            if(t==bt){
                ans.insert(i);
            }
            else if(t<bt){
                bt=t;
                ans.clear();
                ans.insert(i);
            }
        }
    }

    for(int i=0;i<pos;i++){
        int cnt1=0,cnt2=0;
        int t1=0,t2=0;
        for(int j=0;j<26;j++){
            if(solve[i][j]==1){
                cnt1++;
                t1+=time1[i][j];
            }
            else if(solve[i][j]==3){
                cnt2++;
                t2+=time2[i][j];
            }
        }
        if(cnt1==bc && cnt2){
            ans.insert(i);
        }
        else if(cnt1<bc && cnt1+cnt2==bc){
            if(t1+t2<=bt) ans.insert(i);
        }
        else if(cnt1<bc && cnt1+cnt2>bc){
            ans.insert(i);
        }
    }


    vector<string> res;
    for(int x:ans){
        res.push_back(na[x]);
    }
    sort(res.begin(),res.end());
    for(string name:res){
        cout<<name<<" ";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}