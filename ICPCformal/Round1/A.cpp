#include<bits/stdc++.h>
using namespace std;
struct submission{
    int uid;
    int time;
    int pid;
    char res;
    bool operator < (const submission& other) const{
        return time<other.time;
    }
};
struct  score{
    int cnt;
    int ttt;
    bool operator < (const score& other) const{
        if(cnt==other.cnt){
            return ttt>other.ttt;
        }
        return cnt < other.cnt;
    }
};
void solve(){
    int n;
    cin>>n;
    int cnt=0;
    map<string,int> sti;
    vector<string> its;
    vector<submission> subs; 

    for(int i=0;i<n;i++){
        string team,rs;
        int time;
        char pb;
        cin>>team>>pb>>time>>rs;
        if(sti.find(team)==sti.end()){
            sti[team]=cnt++;
            its.push_back(team);
        }
        int pb_id=pb-'A';
        subs.push_back({
            sti[team],
            time,
            pb_id,
            rs[0]
        });   
    }
    vector<vector<int>> pe(cnt,vector<int>(26,0));
    vector<vector<score>> sc(cnt,vector<score>(2));
    for(int i=0;i<cnt;i++){
        for(int j=0;j<2;j++){
            sc[i][j]={0,0};
        }
    }

    sort(subs.begin(),subs.end());
    for(const auto& sub:subs){
        int uid=sub.uid;
        int pid=sub.pid;
        if(pe[uid][pid]==-1) continue;
        if(sub.res=='A'){
            sc[uid][0].cnt++;
            sc[uid][0].ttt+=sub.time+pe[uid][pid];
            pe[uid][pid]=-1;
            sc[uid][1]=sc[uid][0];
        }
        else if(sub.res=='R'){
            pe[uid][pid]+=20;
        }
        else{
            sc[uid][1].cnt++;
            sc[uid][1].ttt+=sub.time+pe[uid][pid];
            pe[uid][pid]=-1; 
        }
    }

    score max_sc=sc[0][0];
    for(int i=0;i<cnt;i++){
        if(max_sc<sc[i][0]){
            max_sc=sc[i][0];
        }
    }
    vector<string> result;
    for(int i=0;i<cnt;i++){
        if(!(sc[i][1]<max_sc)){
            result.push_back(its[i]);
        }
    }
    sort(result.begin(),result.end());
    for(string s:result){
        cout<<s<<" ";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


/*3
4
ASYYPIbf7 D 268 Unknown
3NhYHv8w B 13 Accepted
ASYYPIbf7 B 173 Accepted
dnrkAsPqrA A 107 Accepted
6
T1 A 10Rejected
T1 A 241 Unknown
T1 B 200 Accepted
T2 A 100 Accepted
T3 C 50Accepted
T4 D 250 Unknown
4
Alpha A 100 Accepted
Beta B 100 Accepted
Gamma C 240 Unknown
Delta D 299 Unknown*/