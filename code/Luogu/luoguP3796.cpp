#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

struct trie{
    int fail;
    int son[26];
    int end;
}ac[N];
int p=0;

struct ans{
    int num;
    int pos;
}as[N];

bool operator<(const ans &A,const ans &B){
    if(A.num!=B.num){
        return A.num>B.num;
    }
    else return A.pos<B.pos;
}

void clean(int x){
    memset(ac[x].son,0,sizeof(ac[x].son));
    ac[x].fail=0;
    ac[x].end=0;
}

void build(string s,int id){
    int l=s.size();
    int cur=0;
    for(int i=0;i<l;i++){
        if(ac[cur].son[s[i]-'a']==0){
            ac[cur].son[s[i]-'a']=++p;
            clean(p);
        }
        cur=ac[cur].son[s[i]-'a'];
    }
    ac[cur].end=id;
}

void getf(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(ac[0].son[i]){
            ac[ac[0].son[i]].fail=0;
            q.push(ac[0].son[i]);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(ac[u].son[i]){
                ac[ac[u].son[i]].fail=ac[ac[u].fail].son[i];
                q.push(ac[u].son[i]);
            }
            else ac[u].son[i]=ac[ac[u].fail].son[i];
        }
    }
}

string s[N];

int query(string s){
    int l=s.size();
    int cur=0;
    int res=0;
    for(int i=0;i<l;i++){
        cur=ac[cur].son[s[i]-'a'];
        for(int t=cur;t;t=ac[t].fail){
            as[ac[t].end].num++;
        }
    }
    return res;
}
void solve(int n){
   
    p=0;
    clean(0);

    for(int i=1;i<=n;i++){
        cin>>s[i];
        as[i].num=0;
        as[i].pos=i;
        build(s[i],i);
    }
    ac[0].fail=0;
    getf();

    cin>>s[0];
    query(s[0]);

    sort(as+1,as+1+n);
    cout<<as[1].num<<'\n';
    cout<<s[as[1].pos]<<'\n';
    for(int i=2;i<=n;i++){
        if(as[i].num==as[i-1].num){
            cout<<s[as[i].pos]<<'\n';
        }
        else break;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(true){
        cin>>n;
        if(n==0) break;
        solve(n);
    }
    //system("pause");
    return 0;
}