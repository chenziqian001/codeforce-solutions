#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct trie{
    int fail;
    int son[26];
    int ed;
}ac[N];

int p=0;
void build(string s){
    int l=s.size();
    int cur=0;
    for(int i=0;i<l;i++){
        if(ac[cur].son[s[i]-'a']==0){
            ac[cur].son[s[i]-'a']=++p;
        }
        cur=ac[cur].son[s[i]-'a'];
    }
    ac[cur].ed++;
}

void getf(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(ac[0].son[i]!=0){
            ac[ac[0].son[i]].fail=0;
            q.push(ac[0].son[i]);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(ac[u].son[i]!=0){
                ac[ac[u].son[i]].fail=ac[ac[u].fail].son[i];
                q.push(ac[u].son[i]);
            }
            else ac[u].son[i]=ac[ac[u].fail].son[i];
        }
    }
}

int query(string s){
    int l=s.size();
    int cur=0;
    int res=0;
    for(int i=0;i<l;i++){
        cur=ac[cur].son[s[i]-'a'];
        for(int t=cur;t&&ac[t].ed!=-1;t=ac[t].fail){
            res+=ac[t].ed;
            ac[t].ed=-1;
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    
    for(int i=0;i<n;i++){
        cin>>s;
        build(s);
    }
    getf();
    cin>>s;

    cout<<query(s)<<'\n';
    //system("pause");
    return 0;    
}