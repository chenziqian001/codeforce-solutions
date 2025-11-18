#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int> &fa){
    if(x!=fa[x]){
        fa[x]=find(fa[x],fa);
    }
    return fa[x];
}

void merge(int x,int y,vector<int> &fa){
    int fx=find(x,fa);
    int fy=find(y,fa);
    if(fx!=fy){
        fa[fy]=fx;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    
    if(n%2==0){
        cout<<-1<<'\n';
        return 0;
    }

    vector<array<int,3>> S;
    vector<array<int,3>> M;
    
    for(int i=0;i<m;i++){
        int u,v;
        char tp;
        cin>>u>>v>>tp;
        u--,v--;
        if(tp=='S'){
            S.push_back({u,v,i});
        }
        else{
            M.push_back({u,v,i});
        }
    }

    if(S.size()<(n-1)/2){
        cout<<-1<<'\n';
        return 0;
    }


    vector<int> f1(n);
    for(int i=0;i<n;i++) f1[i]=i;

    int  tt=n;
    for(auto [u,v,id]:M){
        if(find(u,f1)!=find(v,f1)){
            tt--;
            merge(u,v,f1);
        }
    }

    if(((n-1)/2)<tt-1){
        cout<<-1<<'\n';
        return 0;
    }

    vector<int> f2(n);
    for(int i=0;i<n;i++) f2[i]=i; 
    int used_s=0;

    vector<int> res;

    for(auto [u,v,id]:S){
        if(find(u,f1)!=find(v,f1)){
            merge(u,v,f1);
            merge(u,v,f2);
            used_s++;
            res.push_back(id);
        }
    }

    for(int i=0;i<S.size() && used_s<(n-1)/2;i++){
        int u=S[i][0],v=S[i][1],id=S[i][2];
        if(find(u,f2)!=find(v,f2)){
            merge(u,v,f2);
            used_s++;
            res.push_back(id);
        }
    }

    if(used_s!=(n-1)/2){
        cout<<-1<<'\n';
        return 0;
    }

    int used_m=0;

    for(auto [u,v,id]:M){
        if(find(u,f2)!=find(v,f2)){
            merge(u,v,f2);
            used_m++;
            res.push_back(id);
        }
    }

    if(used_m+used_s!=n-1){
        cout<<-1<<'\n';
        return 0;
    }

    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x+1<<" ";
    }
    //system("pause");
}